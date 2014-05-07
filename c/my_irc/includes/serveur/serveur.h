#ifndef		SERVEUR_H_
# define	SERVEUR_H_


/*
** SYSTEM PROTOTYPES
*/

int	rand(void);


/*
** DEFINES
*/

#define RANDOM(min, max)	((rand() % (max - min + 1)) + min)

#define FD_FREE			0
#define FD_SERV			1
#define FD_CLIENT		2

#define BUF_SIZE		4096
#define CHAN_LEN		64
#define NICK_LEN		64
#define SELECT_TIMEOUT		1

#define SERVER_NAME		"#ADMIN#"

/*
** STRUCTURES
*/

typedef struct	s_chan
{
  char		name[CHAN_LEN + 1];
  struct s_chan	*next;
  struct s_chan	*prev;
}		t_chan;

typedef struct	s_fd
{
  void		(*fct_read)();
  char		buf_read[BUF_SIZE + 3];
  int		start;
  int		end;
  int		type;
  char		channel[CHAN_LEN + 1];
  char		nickname[NICK_LEN + 11];
}		t_fd;

typedef struct	s_stck
{
  t_chan	*channel;
  t_fd		*fds;
  fd_set	fd_read;
  int		queue;
  int		lim_fd;
  int		max_fd;
  int		port;
}		t_stck;


#endif /* !SERVEUR_H_ */
