#ifndef		GLOBAL_H_
# define	GLOBAL_H_


/*
** PROTOTYPES
*/

t_incant_token	gl_inc_tok[] =
  {
    {2, 1, 1, 0, 0, 0, 0, 0},
    {3, 2, 1, 1, 1, 0, 0, 0},
    {4, 2, 2, 0, 1, 0, 2, 0},
    {5, 4, 1, 1, 2, 0, 1, 0},
    {6, 4, 1, 2, 1, 3, 0, 0},
    {7, 6, 1, 2, 3, 0, 1, 0},
    {8, 6, 2, 2, 2, 2, 2, 1},
    {0, 0, 0, 0, 0, 0, 0, 0}
  };

t_ressource	gl_res[] =
  {
    {1, "nourriture"},
    {2, "linemate"},
    {3, "deraumere"},
    {4, "sibur"},
    {5, "mendiane"},
    {6, "phiras"},
    {7, "thystame"},
    {8, "joueur"},
    {0, 0}
  };


#endif /* !GLOBAL_H_ */
