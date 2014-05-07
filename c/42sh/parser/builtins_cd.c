#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "x_function.h"
#include "count_fcts.h"
#include "display_fcts.h"
#include "modif_str_fcts.h"
#include "init_env.h"
#include "builtins_env.h"
#include "error.h"

void    edit_locate_env(char *pwd)
{
  char	**args;

  args = xmalloc(10 * sizeof(*args));
  args[0] = "unsetenv";
  args[1] = xmalloc(10 * sizeof(**args));
  strcpy(args[1], "PWD");
  args[2] = NULL;
  args[0] = "setenv";
  strcpy(args[1], "PWD");
  args[2] = pwd;
  args[3] = NULL;
  free(args[1]);
  free(args);
}

void    edit_pwd_env(int size)
{
  char  *buf;

  buf = xmalloc(size * sizeof(*buf));
  buf = getcwd(buf, size);
  while (buf == NULL)
    {
      free(buf);
      size *= 2;
      buf = xmalloc(size * sizeof(*buf));
      buf = getcwd(buf, size);
    }
  edit_locate_env(buf);
  free(buf);
}

void    make_simple_cd(void)
{
  char  *home;
  int   where;
  int   size;
  int   i;

  i = 5;
  where = find_in_env(my_env.my_environ, "HOME=");
  size = strlen(my_env.my_environ[where]) + 1;
  home = xmalloc(size * sizeof(*home));
  while (my_env.my_environ[where][i] != '\0')
    {
      home[i - 5] = my_env.my_environ[where][i];
      i++;
    }
  if (chdir(home) == -1)
    my_put_error("Can't cd to home directory\n", 0);
  if (my_env.pwd != NULL)
    free(my_env.pwd);
  where = find_in_env(my_env.my_environ, "PWD=/");
  my_env.pwd = xmalloc((my_strlen(my_env.my_environ[where])) * sizeof(char));
  my_strdcpy(my_env.pwd, my_env.my_environ[where], 4);
  edit_locate_env(home);
  free(home);
}

void    make_normal_cd(char *dir)
{
  char  *tmp;
  char  *pwd;
  int   where;

  tmp = xmalloc((my_strlen(my_env.pwd) + 1) * sizeof(*tmp));
  my_strcpy(tmp, my_env.pwd);
  if (dir[0] == '-' && dir[1] == '\0' && my_env.pwd != NULL)
    pwd = tmp;
  else
    pwd = dir;
  if (chdir(pwd) == -1)
    {
      my_put_error("Can't cd to ", 0);
      my_put_error(pwd, 0);
      my_put_error("\n", 0);
      return ;
    }
  where = find_in_env(my_env.my_environ, "PWD=/");
  if (my_env.pwd != NULL)
    free(my_env.pwd);
  my_env.pwd = xmalloc(my_strlen(my_env.my_environ[where]) * sizeof(char *));
  my_strdcpy(my_env.pwd, my_env.my_environ[where], 4);
  edit_pwd_env(strlen(my_env.my_environ[where]) + strlen(pwd) + 10);
  free(tmp);
}

int     built_cd(char **arg)
{
  if (!strcmp(arg[0], "cd\0"))
    {
      if (arg[1] == NULL)
        {
          make_simple_cd();
	  return (1);
        }
      else if (arg[1] != NULL && arg[2] == NULL)
        {
          make_normal_cd(arg[1]);
          return (1);
        }
      else if (arg[1] != NULL && arg[2] != NULL)
        {
          my_put_error("cd: Too many arguments.\n", 0);
          return (0);
        }
    }
  return (0);
}
