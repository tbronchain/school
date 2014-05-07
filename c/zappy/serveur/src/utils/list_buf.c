#include <math.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "utils/lib.h"
#include "utils/list_buf.h"
#include "utils/x.h"

static t_buf_c	*get_in_free_list(t_buf *buf, t_stck *s, int p)
{
  t_buf_c	*new;

  new = s->buf_free[p];
  s->buf_free[p] = new->next;
  if (s->buf_free[p])
    (s->buf_free[p])->prev = NULL;
  new->next = NULL;
  new->prev = buf->end;
  if (!buf->begin)
    buf->begin = new;
  new->begin = 0;
  new->end = 0;
  if (buf->end)
    buf->end->next = new;
  buf->end = new;
  return (new);
}

t_buf_c		*new_buffer(t_buf *buf, t_stck *s, int len)
{
  t_buf_c	*new;
  int		p;

  p = len > BUF_MIN ? get_block(len) : get_block(BUF_MIN);
  if (s->buf_free[p])
    return (get_in_free_list(buf, s, p));
  new = Xmalloc(sizeof(t_buf_c));
  new->s = Xmalloc(pow(2, p) + 1);
  new->p = p;
  new->prev = buf->end;
  if (buf->end)
    buf->end->next = new;
  if (!(buf->begin))
    buf->begin = new;
  buf->end = new;
  return (new);
}

void		del_buffer(t_buf *buf, t_stck *s)
{
  t_buf_c	*tmp;

  tmp = buf->begin;
  if (!(buf->begin = buf->begin->next))
    buf->end = NULL;
  tmp->prev = NULL;
  tmp->next = s->buf_free[tmp->p];
  if (tmp->next)
    tmp->next->prev = tmp;
  s->buf_free[tmp->p] = tmp;
}

void		free_buffer(t_buf_c **begin)
{
  t_buf_c	*tmp;

  while (*begin)
    {
      tmp = (*begin)->next;
      free(*begin);
      *begin = tmp;
    }
}

void	free_buffer_list(t_stck *s)
{
  int	i;

  i = 0;
  while (i < 32)
    {
      if (s->buf_free[i])
	free_buffer(&(s->buf_free[i]));
      i++;
    }
}
