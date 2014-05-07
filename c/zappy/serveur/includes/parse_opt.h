#ifndef		PARSE_OPT_H_
# define	PARSE_OPT_H_


/*
** DEFINES
*/

#define OPT_STRING		"p:n:c:x:y:t:"
#define TEAM_LEN		60
#define MAX_PORT		65536
#define OPT_NB			1
#define DEFAULT_OPT_NB		4
#define ERR_GRAPHIC		"name of your team cannot be 'GRAPHIC' or null"
#define ERR_TEAM_LEN		"name of one team is too long"
#define ERR_MAP_X		"X value must be between 1 and 1000"
#define ERR_MAP_Y		"Y value must be between 1 and 1000"
#define ERR_PORT		"port value must be between 1 and 65535"
#define ERR_ACTION_DELAY	"delay should not be null"
#define ERR_NB_CLIENT		"number of client must be positive"
#define ERR_OPT			"Bad number of arguments"
#define SYNOPSIS		"./server -p [port] -n [team_name1,team_name2]"\
  " -c <client_limit> -t <action_delay> -x <map_length> -y <map_wide>"


/*
** STRUCTURES
*/

typedef struct  s_opt
{
  int		opt;
  char          *(*f)();
}               t_opt;

typedef struct	s_parse
{
  int		i;
  int		j;
  int		nb_option;
  int		default_opt;
}		t_parse;

/*
** PROTOTYPES
*/

int	parse_opt(t_stck *s, int ac, char **av);
char	*save_team_opt(t_stck *s, int *nb_opt);
char	*save_map_opt(t_stck *s, int *nb_opt, int opt_char, int *default_opt);
char	*save_opt(t_stck *s, int *nb_opt, int opt_char, int *default_opt);


#endif /* !PARSE_OPT_H_ */
