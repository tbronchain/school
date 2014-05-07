#include <sys/select.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "client/gtk.h"
#include "client/client.h"
#include "client/utils.h"
#include "client/x.h"

void		aff_msg(t_main_win *m, char *message)
{
  GtkTextBuffer	*textbuffer;
  GtkTextMark	*mark;
  GtkTextIter	iter;

  textbuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(m->textview));
  gtk_text_buffer_get_end_iter(textbuffer, &iter);
  gtk_text_buffer_insert(textbuffer, &iter, message, -1);
  mark = gtk_text_buffer_get_insert(textbuffer);
  gtk_text_view_scroll_to_mark(GTK_TEXT_VIEW(m->textview),
			       mark, 0, FALSE, 1, 1);
}

static void	my_gtk_exit(void)
{
  exit(EXIT_SUCCESS);
}

static void	get_msg(GtkWidget *entry, gpointer data)
{
  t_main_win	*m;
  char		*tmp;

  (void)entry;
  m = (t_main_win *)data;
  m->buffer = (gchar *)gtk_entry_get_text(GTK_ENTRY(m->entry));
  tmp = strdup((char *)m->buffer);
  gtk_entry_set_text(GTK_ENTRY(m->entry), "");
  m->buffer = (gchar *)tmp;
}

static void	add_box(t_main_win *m)
{
  m->scrollbar = gtk_scrolled_window_new(NULL, NULL);
  gtk_box_pack_start(GTK_BOX(m->box), m->scrollbar, TRUE, TRUE, 5);
  m->textview = gtk_text_view_new();
  gtk_text_view_set_editable(GTK_TEXT_VIEW(m->textview), FALSE);
  gtk_container_add(GTK_CONTAINER(m->scrollbar), m->textview);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(m->scrollbar),
				 GTK_POLICY_AUTOMATIC,
				 GTK_POLICY_AUTOMATIC);
}

t_main_win	*init_gtk(int *ac, char ***av)
{
  t_main_win	*m;

  gtk_init(ac, av);
  m = Xmalloc(sizeof(t_main_win));
  m->buffer = NULL;
  m->main_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(m->main_win), "CLient my_irc");
  gtk_window_set_default_size(GTK_WINDOW(m->main_win), 600, 400);
  gtk_window_set_position(GTK_WINDOW(m->main_win), GTK_WIN_POS_CENTER);
  g_signal_connect(G_OBJECT(m->main_win), "destroy", G_CALLBACK(my_gtk_exit),
		   NULL);
  m->box = gtk_vbox_new(FALSE, 5);
  gtk_container_add(GTK_CONTAINER(m->main_win), m->box);
  add_box(m);
  m->entry = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(m->entry), BUF_SIZE);
  gtk_box_pack_start(GTK_BOX(m->box), m->entry, FALSE, FALSE, 5);
  m->button = gtk_button_new_with_label("Envoyer");
  gtk_box_pack_start(GTK_BOX(m->box), m->button, FALSE, FALSE, 0);
  g_signal_connect(G_OBJECT(m->button), "clicked", G_CALLBACK(get_msg),
		   (gpointer)m);
  gtk_timeout_add(200, (GtkFunction)null, NULL);
  gtk_widget_show_all(m->main_win);
  return (m);
}
