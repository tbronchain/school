#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/select.h>

const short	BUF_SIZE=4096;
const char* const RBODY="toto=42";
const char* const COMMAND="/usr/bin/php-cgi";
char* const ARGS[] =
  {
    "php-cgi",
    "-n",
    "test.php",
    NULL
  };

int	main(int, char**)
{
  char	buf[BUF_SIZE + 1];
  int	rPipes[2];
  int	wPipes[2];
  int	pid;
  int	status;
  fd_set	 readfds;

  memset(buf, 0, BUF_SIZE + 1);
  if (access(COMMAND, X_OK) == -1)
    {
      std::cerr << "access: PHP open error" << std::endl;
      return -1;
    }

  char* const myEnviron[] = {
    "REDIRECT_STATUS=200",
    "SCRIPT_FILENAME=test.php",
    "PATH_TRANSLATED=test.php",
    "REQUEST_METHOD=GET",
    "CONTENT_TYPE=application/x-www-form-urlencoded",
    //"CONTENT_LENGHT=9",
    NULL
  };

  if (pipe(rPipes) == -1 || pipe(wPipes) == -1)
    {
      std::cerr << "pipe: error" << std::endl;
      return -1;
    }

  if ((pid = fork()) == 0) // son
    {
      close(0);
      close(1);
      close(wPipes[0]);
      close(rPipes[1]);

      if (dup2(wPipes[1], 1) == -1 || dup2(rPipes[0], 0) == -1)
	{
	  std::cerr << "dup2: error" << std::endl;
	  exit(EXIT_FAILURE);
	}
      if (execve(COMMAND, ARGS, myEnviron) == -1)
	{
	  std::cerr << "execve: error" << std::endl;
	  exit(EXIT_FAILURE);
	}
    }
  else if (pid > 0) // father
    {
      close(wPipes[1]);
      close(rPipes[0]);

      /*if (write(rPipes[1], RBODY, strlen(RBODY)) < 0)
      	{
      	  std::cerr << "father pipe: error" << std::endl;
      	  return -1;
	  }*/
      //      close(rPipes[1]);
      struct timeval tv;
      tv.tv_sec = 0;
      tv.tv_usec = 0;
      FD_ZERO(&readfds);
      FD_SET(wPipes[0], &readfds);
      std::cout << "before select" << std::endl;
      for (int n = 0 ; select(wPipes[0], &readfds, NULL, NULL, &tv) != -1 ; )
	{
	  std::cout << "after select" << std::endl;
	  if (FD_ISSET(wPipes[0], &readfds) != -1)
	    {
	      std::cout << "passed isset" << std::endl;
	      if ((n = read(wPipes[0], buf, BUF_SIZE)) > 0)
		{
		  buf[n] = '\0';
		  std::cout << buf;
		}
	      else
		break ;
	    }
	}
    }
  else // error
    {
      perror("fork: error");
      return -1;
    }
  exit(EXIT_SUCCESS);
}

