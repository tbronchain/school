<?php
require_once('./class/pile.class.php');
require_once('./class/actions.class.php');
require_once('./class/stats.class.php');
require_once('./define.php');
require_once('./getOrders.php');

function resolveAction($cmd, $resp, &$actions, &$pile, &$inventory, &$stats)
{
  switch ($cmd["type"])
    {
    case CMD_LOOKAT:
      $actions->resolveLookAt($resp, $inventory, $stats);
      break ;
    case CMD_INVENTORY:
      $actions->resolveInventory($resp, $inventory, $stats);
      break ;
    case CMD_TAKEITEM:
      $actions->resolveTakeItem($resp);
      break ;
    case CMD_DROPITEM:
      $actions->resolveDropItem($resp);
      break ;
    case CMD_CAST_BEGIN:
      $actions->resolveCastFinished($stats);
      break ;
    case CMD_MEMBERTEAM:
      $actions->resolveMemberTeam($resp);
      break ;
    case CMD_FORK:
      if($resp == "ok")
	$pile->setFork(TRUE);
      break ;
    }
}

function cmpCmdToResp($responsesTab, $cmdTab, &$actions, &$pile, &$inventory, &$stats)
{
  if ($responsesTab[0])
    {
      foreach ($responsesTab as $resp)
	{
	  if ($resp[0] == RESP_TEXT_RCV)
	    $actions->resolveTextRcv($resp);
	  else if ($resp[0] == RESP_DEATH)
	    return FALSE;
	  else
	    {
	      resolveAction($cmdTab[0], $resp[1], $actions, $pile, $inventory, $stats);
	      $pile->updatePile();
	    }
	}
    }
  return TRUE;
}

function getIAResp(&$actions)
{
  if ($actions->getCast() == TRUE)
    {
      if ($actions->getTakeList() == NULL)
	return (lookAround());
      $actions->setCast(FALSE);
      return (takeList($actions->getTakeList()));
    }
  else if ($actions->getTakeObj() != NULL)
    {
      $itemToTake = $actions->getTakeObj();
      $actions->setTakeObj(NULL, NULL, 1);
      return (getTotalWay($itemToTake));
    }
  else if ($actions->checkInventory())
    {
      $actions->setInventory(FALSE);
      return (inventory());
    }
  else if ($actions->getFork())
    {
      $actions->setFork(FALSE);
      return (forkAndLook());
    }
  else if ($actions->getNoAction())
    {
      $actions->setNoAction(FALSE);
      return (walkAndLook());
    }
  else if (!$actions->isReaping() && !$actions->checkNoLook())
    {
      $actions->setNoLook(TRUE);
      return (lookAround());
    }
  else
    return (NULL);
}

function resolveActions(&$pile, &$stats, &$inventory, &$actions)
{
  $responsesTab = $pile->getResponses();
  $cmdTab = $pile->getCmd();
  if (empty($responsesTab) == TRUE)
    $cmd = lookAround();
  else
    {
      if (cmpCmdToResp($responsesTab, $cmdTab, $actions, $pile, $inventory, $stats) == FALSE)
	return (FALSE);
      $cmd = getIAResp($actions);
      if ($cmd[0]["cmd"] != "voir")
	$actions->setNoLook(FALSE);
    }
  $pile->addToPile($cmd);
  return (TRUE);
}
?>