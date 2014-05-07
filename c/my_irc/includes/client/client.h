#ifndef		CLIENT_H_
# define	CLIENT_H_


/*
** DEFINES
*/

#define DEFAULT_PORT	6662
#define BUF_SIZE	4096


/*
** STRUCTURES
*/

typedef struct s_main
{
  t_main_win	*m;
  fd_set	fd_read;
  char		**tab;
  char		*host;
  char		buf[BUF_SIZE];
  int		start;
  int		end;
  int		port;
  int		sfd;
  int		connect;
}		t_main;

#endif /* !CLIENT_H_ */
