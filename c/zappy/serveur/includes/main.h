#ifndef		MAIN_H_
# define	MAIN_H_


/*
** DEFINES
*/

#define RANDOM(min, max)	((rand() % (max - min + 1)) + min)

enum {
  FD_FREE,
  FD_SERV,
  FD_CLIENT,
  FD_GRAPH,
  FD_IA,
  FD_EGG
};

#define BUF_SIZE		1024
#define BUF_MAX			(4096 * 16)
#define BUF_MIN			32
#define MAX_SEND		1000
#define MAX_ERR			100

#define MAX_X			1000
#define MAX_Y			1000

#define TEAM_LEN		60
#define DEFAULT_X		20
#define DEFAULT_Y		20
#define DEFAULT_TIME		100
#define DEFAULT_NB_CLIENT	20
#define FOOD_INCREASE		5
#define STONE_INCREASE		1
#define END_LEVEL		8

#define REF			(9 / 30)

/*
** STRUCTURES
*/

typedef struct		s_ban
{
  char			*ip;
  struct s_ban		*next;
}			t_ban;

typedef struct		s_gparam
{
  int			fd;
  int			x;
  int			y;
  int			n;
  int			i;
  int			e;
  int			inc_nb;
  int			inc_res;
  int			*inc;
  char			*msg;
  char			*team;
}			t_gparam;

typedef struct		s_incant_token
{
  int			level;
  int			nb_players;
  int			linemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			t_incant_token;

typedef struct		s_ressource
{
  int			type;
  char			*name;
}			t_ressource;

typedef struct		s_wait
{
  int			id;
  int			use;
  int			fd;
  int			sec;
  int			usec;
  int			(*funct_wait)();
  char			*cmd;
  int			type;
  struct s_wait		*prev;
  struct s_wait		*next;
}			t_wait;

typedef struct		s_egg
{
  int			id;
  int			x;
  int			y;
  int			status;
  char			team[TEAM_LEN];
  t_wait		*death;
  struct s_egg		*prev;
  struct s_egg		*next;
}			t_egg;

typedef struct		s_teams
{
  char			*team;
  int			c;
  struct s_teams	*next;
}			t_teams;

typedef struct		s_buf_c
{
  char			*s;
  int			begin;
  int			end;
  int			p;
  struct s_buf_c	*prev;
  struct s_buf_c	*next;
}			t_buf_c;

typedef struct		s_buf
{
  t_buf_c		*begin;
  t_buf_c		*end;
  int			len;
  int			max;
}			t_buf;

typedef struct		s_case
{
  int			food;
  int			linemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
  int			players;
}			t_case;

typedef struct		s_fd
{
  int			id;
  int			type;
  int			(*fct_read)();
  int			(*fct_write)();
  char			*tmode;
  t_buf			cbuf_read;
  t_buf			cbuf_write;
  char			*buf_read;
  char			*buf_write;
  t_wait		*death;
  t_wait		*wait;
  int			nb_wait;
  char			*team;
  int			x;
  int			y;
  int			level;
  t_case		invent;
  int			view;
  int			err;
  char			*ip;
  int			fd;
}			t_fd;

typedef struct		s_map
{
  t_case		*map;
  int			x;
  int			y;
}			t_map;

typedef struct		s_stck
{
  t_buf_c		*buf_free[32];
  t_fd			*fds;
  fd_set		fd_r;
  fd_set		fd_w;
  int			lim_fd;
  int			max_fd;
  int			max_egg;
  int			port;
  t_wait		*timeout;
  t_egg			*egg;
  char			**teams;
  t_teams		*teams_list;
  int			t;
  int			max_tclient;
  t_map			map;
  t_ban			*ban;
  int			end;
  char			*win;
}			t_stck;

#endif /* !MAIN_H_ */
