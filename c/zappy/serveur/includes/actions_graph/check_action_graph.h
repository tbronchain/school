#ifndef		CHECK_ACTION_GRAPH_H_
# define	CHECK_ACTION_GRAPH_H_

/*
** PROTOTYPES
*/

int	check_action_graph(t_stck *s, int fd, char *buf);


/*
** STRUCTURES
*/

typedef struct	s_cmd_graph
{
  char		*cmd;
  char		*(*funct)();
}		t_cmd_graph;


#endif /* !CHECK_ACTION_GRAPH_H_ */
