#ifndef		GTK_H_
# define	GTK_H_


/*
** STRUCTURES
*/

typedef struct	s_main_win
{
  GtkWidget	*main_win;
  GtkWidget	*box;
  GtkWidget	*entry;
  GtkWidget	*button;
  GtkWidget	*textview;
  GtkWidget	*scrollbar;
  gchar		*buffer;
}		t_main_win;


/*
** PROTOTYPES
*/

void		aff_msg(t_main_win *m, char *message);
t_main_win	*init_gtk(int *ac, char ***av);


#endif /* !GTK_H_ */
