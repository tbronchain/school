<?php
define("DEATH", -1);
define("OK", 1);

define("READ_SIZE", 1024);

/* Types de r?ponses du serveur */
define("RESP_KO", 0);
define("RESP_OK", 1);
define("RESP_INVENTORY", 2);
define("RESP_LOOKAT", 3);
define("RESP_ELEVATION", 4);
define("RESP_NAME", 5);
define("RESP_DEATH", 6);
define("RESP_TEXT_RCV", 7);

/* Types de commandes du client */
define("CMD_WALK", 0);
define("CMD_RIGHT", 1);
define("CMD_LEFT", 2);
define("CMD_LOOKAT", 3);
define("CMD_INVENTORY", 4);
define("CMD_TAKEITEM", 5);
define("CMD_DROPITEM", 6);
define("CMD_PUSH", 7);
define("CMD_TEXT", 8);
define("CMD_CAST_FINISHED", 9);
define("CMD_FORK", 10);
define("CMD_MEMBERTEAM", 11);
define("CMD_CAST_BEGIN", 12);

/* Temps pour chaque commande */
define("TIME_WALK", 7);
define("TIME_RIGHT", 7);
define("TIME_LEFT", 7);
define("TIME_LOOKAT", 7);
define("TIME_INVENTORY", 1);
define("TIME_TAKEITEM", 7);
define("TIME_DROPITEM", 7);
define("TIME_PUSH", 7);
define("TIME_TEXT", 7);
define("TIME_CAST", 300);
define("TIME_FORK", 42);
define("TIME_TEAMNAME", 0);

/*  Nombres maximum par pierres precieuses */
define("MAX_LINEMATE", 9);
define("MAX_DERAUMERE", 8);
define("MAX_SIBUR", 10);
define("MAX_MENDIANE", 5);
define("MAX_PHIRAS", 6);
define("MAX_THYSTAME", 1);

define("MIN_FOOD", 10);

define("FOOD", "nourriture");
define("PLAYER", "joueur")
?>