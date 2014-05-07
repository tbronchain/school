#ifndef		VIEW_IA_H_
# define	VIEW_IA_H_

/*
** DEFINES
*/

#define HAUT		0
#define DROITE		1
#define BAS		2
#define GAUCHE		3

typedef struct	s_line_view
{
  char		*case_content;
  char		*view_content;
  int		*first_coord;
  int		*end_coord;
  int		coord_type;
  int		alloc_len;
  int		is_first;
}		t_view;

/*
** PROTOTYPES
*/

void	get_alloc_view(t_stck *s, int fd, t_view *v);
void	get_view_content(t_stck *s, t_view *v, int fd);

#endif /* !VIEW_IA_H_ */
