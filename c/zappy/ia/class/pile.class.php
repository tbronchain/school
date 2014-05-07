<?php
require_once('./define.php');

class pile
{
  private $cmdTab;
  private $unSendCmdTab;
  private $responsesTab;
  private $nbCommandInProgress;
  private $doFork;

  function __construct()
  {
    $this->cmdTab = array(array());
    array_shift($this->cmdTab);
    $this->responsesTab = array(array());
    array_shift($this->responsesTab);
    $this->unSendCmdTab = array();
    array_shift($this->unSendCmdTab);
    $this->nbCommandInProgress = 0;
  }

  function checkResponseType($response)
  {
    if (strcmp($response, "ok\n") == 0)
      return (RESP_OK);
    else if (strcmp($response, "ko\n") == 0)
      return (RESP_KO);
    else if (strcmp($response, "mort\n") == 0)
      {
	echo "A perdu la tete !\n";
	return (RESP_DEATH);
      }
    else if (strcmp($response, "elevation en cours\n") == 0)
      return (RESP_ELEVATION);
    else if (strncmp($response, "message ", 12) == 0)
      return (RESP_TEXT_RCV);
    else if (strncmp($response, "{nourriture ", 12) == 0)
      return (RESP_INVENTORY);
    else if (strncmp($response, "{ ", 2) == 0)
      return (RESP_LOOKAT);
    else
      return (RESP_NAME);
  }

  function addResponses($client)
  {
    $write = NULL;
    $except = NULL;
    $nbSocks = 0;
    $read[0] = $client->getSocket();
    if (($response[1] = @socket_read($client->getSocket(), READ_SIZE)) == FALSE)
      {
	echo "Error with reading on socket.\n";
	exit (-1);
      }
    echo "\033[0;31m";
    echo "Receive -> " . $response[1];
    echo "\033[0m";
    $response[0] = $this->checkResponseType($response[1]);
    array_push($this->responsesTab, $response);
    if ($this->nbCommandInProgress >= 0)
      $this->nbCommandInProgress--;
  }

  function checkFork()
  {
    return ($this->doFork);
  }

  function setFork($bool)
  {
    $this->doFork = $bool;
  }

  function getResponses()
  {
    return ($this->responsesTab);
  }

  function getCmd()
  {
    return ($this->cmdTab);
  }

  function getUnSendCmdTab()
  {
    return ($this->unSendCmdTab);
  }

  function addToPile($cmd)
  {
    if ($cmd)
      {
	foreach ($cmd as $elem)
	  {
	    if ($elem)
	      array_push($this->unSendCmdTab, $elem);
	  }
      }
  }

  function updatePile()
  {
    array_shift($this->cmdTab);
    array_shift($this->responsesTab);
  }
  
  function updateRespPile()
  {
    array_shift($this->responsesTab);
  }
  
  function sendCmd($client, &$actions)
  {
    echo "\033[0;33m";
    echo "Sending -> " . $this->unSendCmdTab[0]["cmd"] . "\n";
    echo "\033[0m";
    if (@socket_write($client->getSocket(), $this->unSendCmdTab[0]["cmd"] . "\n", strlen($this->unSendCmdTab[0]["cmd"]) + 1) == FALSE)
      {
	echo "Error with writting on Socket.\n";
	exit (-1);
      }
    array_push($this->cmdTab, $this->unSendCmdTab[0]);
    array_shift($this->unSendCmdTab);
  }
}
?>