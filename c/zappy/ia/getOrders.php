<?php
function getTotalWay($itemTab)
{
  $orderTab = array(array());
  $dest = $itemTab["case"];
  $item = $itemTab["item"];
  if ($dest == 0)
    return (array(array("type" => CMD_TAKEITEM, "cmd" => "prend " . $item)));
  if ($dest <= 3)
    {
      $y = 1;
      $leftMax = 1;
      $rightMax = 3;
      $midCase = 2;
    }
  else if ($dest <= 8)
    {
      $y = 2;
      $leftMax = 4;
      $rightMax = 8;
      $midCase = 6;
    }
  else
    {
      $y = 3;
      $leftMax = 9;
      $rightMax = 15;
      $midCase = 12;
    }
  while ($y-- > 0)
    $orderTab[] = array("type" => CMD_WALK, "cmd" => "avance");
  if ($dest > $midCase)
    {
      $orderTab[] = array("type" => CMD_RIGHT, "cmd" => "droite");
      $i = $midCase;
      while ($i++ < $rightMax)
	$orderTab[] = array("type" => CMD_WALK, "cmd" => "avance");
    }
  else if ($dest < $midCase)
    {
      $orderTab[] = array("type" => CMD_LEFT, "cmd" => "gauche");
      $i = $midCase;
      while ($i-- > $leftMax)
        $orderTab[] = array("type" => CMD_WALK, "cmd" => "avance");
    }
  $orderTab[] = array("type" => CMD_TAKEITEM, "cmd" => "prend " . $item);
  $orderTab[] = array("type" => CMD_INVENTORY, "cmd" => "inventaire");
  return ($orderTab);
}

function countNbrMove($dest)
{
  $orderTab = array(array());
  $count = 1;
  if ($dest == 0)
    return $count;
  if ($dest <= 3)
    {
      $y = 1;
      $leftMax = 1;
      $rightMax = 3;
      $midCase = 2;
    }
  else if ($dest <= 8)
    {
      $y = 2;
      $leftMax = 4;
      $rightMax = 8;
      $midCase = 6;
    }
  else
    {
      $y = 3;
      $leftMax = 9;
      $rightMax = 15;
      $midCase = 12;
    }
  while ($y-- > 0)
    $count++;
  if ($dest > $midCase)
    {
      $count++;
      $i = $midCase;
      while ($i++ < $rightMax)
        $count++;
    }
  else if ($dest < $midCase)
    {
      $count++;
      $i = $midCase;
      while ($i-- > $leftMax)
        $count++;
    }
  return ($count);
}

function lookAround()
{
  return (array(array("type" => CMD_LOOKAT, "cmd" => "voir")));
}

function walkAndLook()
{
  $order[0]["type"] = CMD_WALK;
  $order[0]["cmd"] = "avance";
  $order[1]["type"] = CMD_LOOKAT;
  $order[1]["cmd"] = "voir";
  return ($order);
}

function forkAndLook()
{
  $order[0]["type"] = CMD_FORK;
  $order[0]["cmd"] = "fork";
  $order[1]["type"] = CMD_LOOKAT;
  $order[1]["cmd"] = "voir";
  return ($order);
}

function inventory()
{
  return (array(array("type" => CMD_INVENTORY, "cmd" => "inventaire")));
}

function takeList($itemList)
{
  $orderTab = array();
  $i = 0;
  foreach ($itemList as $elem)
    {
      if ($elem)
	{
	  $order[$i]["type"] = CMD_TAKEITEM;
	  $order[$i++]["cmd"] = "prend " . $elem;
	}
    }
  $order[$i]["type"] = CMD_DROPITEM;
  $order[$i++]["cmd"] = "pose linemate";
  $order[$i]["type"] = CMD_CAST_BEGIN;
  $order[$i++]["cmd"] = "incantation";
  $orderTab[] = array("type" => CMD_INVENTORY, "cmd" => "inventaire");
  return ($order);
}
?>