<?php
class stats
{
  private $life;
  private $level;
  private $team;
  private $wSizeX;
  private $wSizeY;

  function __construct()
  {
    $this->life = 10;
    $this->level = 1;
    $this->team = 0;
  }

  function setTeam($team)
  {
    $this->team = $team;
  }

  function getTeam()
  {
    return ($this->team);
  }

  function setLevel()
  {
    $this->level++;
  }

  function setWorldSize($size)
  {
    $this->wSizeX = $size[0];
    $this->wSizeY = $size[1];
  }

  function getLevel()
  {
    return ($this->level);
  }

  function setLife($life)
  {
    $this->life = $life;
  }

  function getLife()
  {
    return ($this->life);
  }

  function clientAlive()
  {
    if ($this->life <= 0)
      return FALSE;
    return TRUE;
  }
}
?>
