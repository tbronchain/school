#ifndef MY_SELECT_H_
# define MY_SELECT_H_

/* ASCII MEMO */
/*
** DEL = 27 91 51 126
** KU = 27 91 65
** KD = 27 91 66
*/

/* Define Porta */

#ifndef TIOCGETA
# define TIOCGETA	TCGETS
#endif

#ifndef TIOCSETA
# define TIOCSETA	TCSETS
#endif

#ifndef TCSASOFT
# define TCSASOFT	0
#endif

#ifndef CIGNORE
# define CIGNORE	0
#endif

#ifndef TIOCSETAW
# define TIOCSETAW	0
#endif

#ifndef TIOCSETAF
# define TIOCSETAF	0
#endif

/* Define ASCII num */

#define DEL	127
#define ESC	27
#define KU	65
#define KD	66
#define SP	32
#define RET	10
#define BSP	8

/* Define colors */

#define GREY	"\033[1;30m"
#define RED	"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define PINK	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define DEFAULT	"\033[00m"

/* Define eroor messages */

#define ERR_ARGV "Syntax error.\n""Syntax is : my_select [SELECTION]\n"
#define ERR_MALLOC "FATAL error of 'malloc()' fonction.\n"
#define ERR_READ "FATAL error of 'read()' fonction.\n"
#define ERR_OPEN "FATAL error of 'open()' fonction.\n"
#define ERR_CLOSE "FATAL error of 'close()' fonction.\n"
#define ERR_TCGET "FATAL error of 'my_tcgetattr()' fonction.\n"
#define ERR_TCSET "FATAL error of 'my_tcsetattr()' fonction.\n"
#define ERR_TGETENT "FATAL error of 'tgetent()' fonction.\n"
#define ERR_TGETSTR "FATAL error of 'tgetstr()' fonction.\n"
#define ERR_TERM "Can't determine terminal.\n"
#define ERR_TGOTO "FATAL error of 'tgoto()' fonction.\n"
#define ERR_IOCTL "FATAL error of 'ioctl()' fonction.\n"
#define ERR_SIZE "Please, resize your terminal.\n"
#define ERR_OTH "Unknow error of system fonction.\n"

/* Define buffer size */

#define BUF_SIZE	4096

/* Struct */

typedef struct	s_area
{
  char		**av;
  char		*res;
  char		*term;
  char		buff[BUF_SIZE];
  char		bp[1024];
  char		t[4096];
  char		*area;
  char		*clstr;
  char		*cmstr;
  char		*sostr;
  char		*sestr;
  char		*usstr;
  char		*uestr;
  int		li;
  int		co;
  int		x;
  int		y;
  int		len;
  int		ac;
  int		size;
}		t_area;

/* Prototypes */

void	my_ncpy(void *src, void *dest, int n);
void	my_putchar(char c);
void    my_put_arg(char *str);
int	my_putstr(char *str);
int	my_put_error(char *str);
int	my_strlen(char *str);
int	my_put_nbr(int n);
void	x_write(int x);
void	x_read(int n);
void	x_tcgetattr(int n);
void	x_tcsetattr(int n);
void	x_tgetent(int n);
void	x_malloc(char *str, int size);
int	my_outc(int c);
char	*cpy_from_env(char **tab, char *str);
char	*make_str(char *found, char *src);
char	*cpy_from_env(char **tab, char *str);
void	x_tgetstr(char *capstr, char *cap);
char	*xtgetstr(char *cap, char **area);
int	my_tab_len(char **tab);
char	*my_strcpy(char *dest, char *src);
void	x_malloc_2d(char **tab, int size);
void	my_arg_cpy(t_area *ar, char **argv, int argc);
void	my_aff_tab(char **tab);
void	init_size(t_area *ar, char **argv);
void	init_term(t_area *ar, char **argv, int argc);
void	aff_arg(t_area *ar);
void	free_struct(t_area *ar);
void	display_arguments(t_area *ar);
void	aff_old_select(t_area *ar);
void	display_arguments(t_area *ar);
void	check_keys(t_area *ar, int len);
void	check_select(t_area *ar);
void	aff_void(t_area *ar, int ac, int y);
void	make_delete_mid(t_area *ar, int ac, int y);
void	make_delete_end(t_area *ar, int y);
int	check_delete(t_area *ar);
char	*x_tgoto(const char *cap, int col, int row);
int	make_argc(t_area *ar, int argc);
void	check_ctrl(t_area *ar);
void	x_oth(int n);
int	my_strcmp(char *s1, char *s2);

#endif /* MY_SELECT_H_ */
