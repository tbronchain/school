#ifndef STRUCT_TERMCAP_H__
# define STRUCT_TERMCAP_H__

#define SIZE 1024
#define BUF_SIZE 4096

typedef struct			s_list_recup_char
{
  char				c;
  struct s_list_recup_char	*next;
  struct s_list_recup_char	*back;
}				t_list_recup_char;

typedef struct		s_term
{
  char			*area;
  char			*clstr;
  char			*cmstr;
  char			*blstr;
  char			*rcstr;
  char			*scstr;
  char			*crstr;
  char			*cdstr;
  char			*ndstr;
  char			*upstr;
  char			*lestr;
  char			*dostr;
  char			*term;
  char			bp[SIZE];
  char			t[BUF_SIZE];
  char			buf[BUF_SIZE];
  int			cc;
  int			x;
  int			x_prompt;
  int			x_max;
  int			x_winmax;
  int			y_prompt;
  int			y;
  int			y_max;
  int			flag;
  char			*command;

}			t_term;

#endif /* STRUCT_TERMCAP_H_ */

