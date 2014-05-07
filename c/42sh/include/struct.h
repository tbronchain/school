#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct  s_list
{
  char          *data;
  struct s_list *next;
}               t_list;

typedef struct          s_list_2d
{
  char                  **data;
  struct s_list_2d      *next;
}                       t_list_2d;

typedef struct  s_env
{
  int           nbp;
  int           nb1;
  int           nb2;
  int           size;
  int           prompt_flag;
  char          *s;
  char          *tmp;
  char          *pwd;
  char          *prompt;
  char          **my_environ;
  char          **path;
  char          **args;
  char          **splitp;
  t_list        *begin;
  t_list_2d     *argsp;
}               t_env;

t_env   my_env;

typedef struct	s_parsing
{
  char		*save_tmp;
  char		*tmp;
  int		ret;
}		t_parsing;

typedef struct	s_pipe
{
  int		id;
  int		(*fct)();
}		t_pipe;

typedef	struct	s_built
{
  char		*name;
  int		(*fct)();
}		t_built;

typedef struct	s_quote
{
  char		*str;
  int		quote;
  int		j;
}		t_quote;

typedef struct	s_token
{
  char		*token;
  char		val;
  int		len;
  int		replace;
  int		valid_sep;
}		t_token;

typedef struct		s_logic
{
  char			*command;
  int			and_or;
  struct s_logic	*next;
}			t_logic;

#endif /* STRUCT_H_ */

