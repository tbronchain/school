#!/usr/local/bin/php -c/u/all/nirlo-_n/public/php.ini
<?php
require_once('./class/client.class.php');
require_once('./class/inventory.class.php');
require_once('./class/pile.class.php');
require_once('./class/actions.class.php');
require_once('./actions.php');

function getGameInfo($client, $stats)
{
  socket_write($client->getSocket(), $client->getTeam() . "\n", strlen($client->getTeam()) + 1);
  if (($response = @socket_read($client->getSocket(), READ_SIZE)) == FALSE)
    {
      echo "Probleme during getting game infos\n";
      return FALSE;
    }
  $info = explode('\n', $response);
  /*if (intval($info[0]) == -1)
    {
      echo "This team is already full.\n";
      return FALSE;
    }*/
  $stats->setTeam($client->getTeam());
  echo $info[1] ."\n";
  if ($info[1] == NULL)
    {
      $response = socket_read($client->getSocket(), READ_SIZE);
      $wSize = explode(' ', $response);
    }
  else
    $wSize = explode(' ', $info[1]);
  $stats->setWorldSize($wSize);
  return TRUE;
}

function doFork($argv)
{
  $pid = pcntl_fork();
  if ($pid == -1)
    die('Error with fork.\n');
  else if (!$pid)
    {
      main($argv);
      exit (0);
    }
}

function mainLoop(&$client, &$stats, $argv)
{
  $inventory = new inventory();
  $pile = new pile();
  $actions = new actions();
  while ($stats->clientAlive() == TRUE)
    {
      if (resolveActions($pile, $stats, $inventory,$actions) == FALSE)
	break;
      $pile->sendCmd($client, $actions);
      $pile->addResponses($client);
      if ($pile->checkFork() == TRUE)
	{
	  $pile->setFork(FALSE);
	  doFork($argv);
	}
    }
}

function main($argv)
{
  $client = new client($argv);
  $stats = new stats();
  if ($client->checkExit() == TRUE)
    return ;
  if (($sock = @socket_create(AF_INET, SOCK_STREAM, getprotobyname('tcp'))) == FALSE)
    {
      echo "Error with creating socket.\n";
      return ;
    }
  $client->setSocket($sock);
  socket_bind($sock, $client->getIp());
  if (@socket_connect($client->getSocket(), $client->getIp(), $client->getPort()) == FALSE)
    {
      echo "Can't connect to socket.\n";
      return ;
    }
  echo socket_read($client->getSocket(), 512);
  if (getGameInfo($client, $stats) == TRUE)
    mainLoop($client, $stats, $argv);
  socket_close($client->getSocket());
}

main($argv);

?>
