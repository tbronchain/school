<?php
require_once('./class/inventory.class.php');
require_once('./class/stats.class.php');

class actions
{
  private $push;
  private $walk;
  private $inventory;
  private $sendText;
  private $cast;
  private $lookAround;
  private $fork;
  private $takeObj;
  private $memberTeam;
  private $noAction;
  private $waitingForElev;
  private $reaping;
  private $lastAction;
  private $noLook;

  function __construct()
  {
    $this->push = 0;
    $this->walk = 0;
    $this->inventory = FALSE;
    $this->sendText = 0;
    $this->cast = 0;
    $this->memberTeam = 0;
    $this->lookAround = 0;
    $this->takeObj = array();
    $this->noAction = FALSE;
    $this->waitingForElev = FALSE;
    $this->reaping = FALSE;
    $this->lastAction = NULL;
    $this->fork = FALSE;
    $this->takeList = NULL;
    $this->noLook = FALSE;
  }

  function setTakeObj($case, $item, $flag)
  {
    $this->takeObj["case"] = $case;
    $this->takeObj["item"] = $item;
    if ($flag == 1)
      $this->takeObj = NULL;
  }

  function setLastAction($action)
  {
    $this->lastAction = $action;
  }

  function setNoAction($bool)
  {
    $this->noAction = $bool;
  }

  function setNoLook($bool)
  {
    $this->noLook = $bool;
  }

  function setFork($bool)
  {
    $this->fork = $bool;
  }

  function setInventory($bool)
  {
    $this->inventory = $bool;
  }

  function setCast($bool)
  {
    $this->waitingForElev = $bool;
  }

  function checkNoLook()
  {
    return ($this->noLook);
  }

  function getCast()
  {
    return ($this->waitingForElev);
  }

  function getFork()
  {
    return ($this->fork);
  }

  function getTakeObj()
  {
    return ($this->takeObj);
  }

  function getNoAction()
  {
    $this->inventory = FALSE;
    return ($this->noAction);
  }

  function getLastAction()
  {
    return ($this->lastAction);
  }

  function getTakeList()
  {
    return ($this->takeList);
  }

  function isReaping()
  {
    return ($this->reaping);
  }

  function checkInventory()
  {
    return ($this->inventory);
  }

  function resolveLookat($resp, $inventory, $stats)
  {
    $case = 0;
    $tmp = explode(",", trim(substr($resp, 1, strlen($resp) - 3)));
    $this->noAction = TRUE;
    $this->takeList = NULL;
    foreach ($tmp as $elem)
      {
	$objects = explode(" ", $elem);
	foreach ($objects as $obj)
	  {
	    if ($this->waitingForElev == TRUE)
		$this->takeList[] = $obj;
	    else
	      {
		if ($obj && $obj != PLAYER)
		  if ($inventory->checkUtility($obj, $stats, $this->takeObj["item"], $case) == TRUE)
		    {
		      $this->setTakeObj($case, $obj, 0);
		      $this->noAction = FALSE;
		      $this->reaping = TRUE;
		    }
	      }
	  }
	  if ($this->waitingForElev == TRUE)
	     return ;
	$case++;
      }
    echo "\033[0;32m";
    echo "item choisi : " . $this->takeObj["item"] . "\ncase : " . $this->takeObj["case"] . "\n";
    echo "\033[0m";
  }

  function resolveMemberTeam($resp, $stats)
  {
    if ($resp[1] <= 1)
      $this->fork = TRUE;
  }

  function resolveTakeItem($resp)
  {
    $this->takeObj = NULL;
    $this->reaping = FALSE;
    if ($resp[0] == RESP_KO)
      $this->lookAround = 1;
  }

  function resolveDropItem($resp)
  {
    if ($resp[0] == RESP_KO)
      $this->inventory = TRUE;
  }

  function resolveCastFinished(&$stats)
  {
    $stats->setLevel();
    $this->memberTeam = 1;
    $this->waitingForElev = FALSE;
    $this->fork = TRUE;
  }

  function resolveInventory($resp, $inventory, $stats)
  {
    $inventory->setInventory($resp[1]);
    if ($inventory->checkInventoryForCast($stats))
      $this->waitingForElev = TRUE;
    else
      $this->lookAround = 1;
  }
}
?>
