<?php
require_once('./class/stats.class.php');
require_once('./class/actions.class.php');
require_once('./define.php');
require_once('./getOrders.php');

class inventory
{
  private $linemate;
  private $deraumere;
  private $sibur;
  private $mendiane;
  private $phiras;
  private $thystame;
  private $food;

  function __construct()
  {
    $this->linemate = 0;
    $this->deraumere = 0;
    $this->sibur = 0;
    $this->mendiane = 0;
    $this->phiras = 0;
    $this->thystame = 0;
    $this->food = 10;
  }

  function checkUtility($obj, $stats, $bestObj, $case)
  {
    $max_move = $this->food * 18;
    $movements = countNbrMove($case);
    $level = $stats->getLevel();
    if ($bestObj != $obj)
      {
	if (!strcmp($obj, FOOD))
	  return TRUE;
	else if ($thid->food > MIN_FOOD)
	  switch ($level)
	    {
	    case 1:
	      if (!strcmp($obj, "linemate") && $this->linemate != MAX_LINEMATE)
		{
		  if ($movements < ($this->food * 18))
		    return TRUE;
		  return FALSE;
		}
	      break ;
	    case 2:
	      if ($bestObj != NULL)
		{
		  if (!strcmp($obj, "linemate") && $this->linemate < 1 && $movements < ($this->food * 18))
		    return TRUE;
		  if (!strcmp($obj, "deraumere") && $this->deraumere < 1 && $movements < ($this->food * 18))
		    return TRUE;
		  if (!strcmp($obj, "sibur") && $this->sibur < 1 && $movements < ($this->food * 18))
		    return TRUE;
		  if ($this->$bestObj > 0)
		    return TRUE;
		  return FALSE;
		}
	      break ;
	    }
      }
    else
      {
	if ($this->takeObj["case"] == 0)
	  return FALSE;
	else if (($case == 2) || ($case == 6))
	  return TRUE;
      }
    return FALSE;
  }
  
  function setInventory($answer)
  {
    $tmp = explode(",", $answer);
    if ($tmp)
      {
        foreach ($tmp as $tmpItem)
          {
            $item = explode(' ', $tmpItem);
            $items[$item[0]] = intval($item[1]);
          }
        foreach ($items as $item => $nb)
	  {
	    if (isset($this->$item))
	      $this->$item = $nb;
	  }
      }
  }

  function checkInventoryForCast($stats)
  {
    $level = $stats->getLevel();
    switch ($level)
      {
      case 1:
	if ($this->linemate = 1)
	  return TRUE;
	break ;
      case 2:
	if ($this->linemate >= 1 && $this->deraumere >= 1 && $this->sibur >= 1)
	  return TRUE;
	break ;
      case 3:
	if ($this->linemate >= 2 && $this->sibur >= 1 && $this->phiras >= 2)
	  return TRUE;
	break ;
      case 4:
	if ($this->linemate >= 1 && $this->deraumere >= 1 && $this->sibur >= 2 && $this->phiras >= 1)
	  return TRUE;
	break ;
      case 5:
	if ($this->linemate >= 1 && $this->deraumere >= 2 && $this->sibur >= 1 && $this->mendiane >= 3)
	  return TRUE;
	break ;
      case 6:
	if ($this->linemate >= 1 && $this->deraumere >= 2 && $this->sibur >= 3 && $this->phiras >= 1)
	  return TRUE;
	break ;
      case 7:
	if ($this->linemate >= 2 && $this->deraumere >= 2 &&$this->sibur >= 2
	    && $this->mendiane >= 2 && $this->phiras >= 2 && $this->thystame == 1)
	  return TRUE;
	break ;
      }
    return FALSE;
  }
}
?>
