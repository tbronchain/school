<?php
class client
{
  private $ip;
  private $port;
  private $socket;


  function __construct($argv)
  {
    $this->exit = 0;
    $tmp = array("-n", "-h", "-p");
    foreach ($tmp as $option)
      {
        $key = array_search($option, $argv);
        if ($key == FALSE && $option != "-h")
          {
            echo "Usage [-n team] [-p port] [-h host]\n";
            $this->exit = 1;
            return ;
          }
        if ($option == "-h" && $key == FALSE)
          $this->ip = "127.0.0.1";
        else if ($argv[$key + 1] && $option == "-h")
          $this->ip = $argv[$key + 1];
        else if ($argv[$key + 1] && $option == "-n")
          $this->team = $argv[$key + 1];
        else if ($argv[$key + 1] && $option == "-p" && is_int(intval($argv[$key + 1])))
	  $this->port = intval($argv[$key + 1]);
        else
          {
            echo "Usage [-n team] [-p port] [-h host]\n";
            $this->exit = 1;
            return ;
          }
      }
  }

  function getIp()
  {
    return ($this->ip);
  }

  function getPort()
  {
    return ($this->port);
  }

  function getSocket()
  {
    return ($this->socket);
  }

  function getTeam()
  {
    return ($this->team);
  }

  function checkExit()
  {
    if ($this->exit == 1)
      return TRUE;
    return FALSE;
  }

  function setSocket($socket)
  {
    $this->socket = $socket;
  }
}
?>
