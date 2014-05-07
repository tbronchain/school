#include <math.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "transfer/send.h"
#include "transfer/recv.h"
#include "utils/cbuf.h"
#include "utils/free.h"
#include "utils/lib.h"
#include "utils/list_buf.h"
#include "utils/kick.h"
#include "utils/x.h"

static char	*select_mode(t_stck *s, int fd, char *buf)
{
  if (s->fds[fd].tmode)
    return (str_clean(buf));
  else if (strstr(buf, "\r\n"))
    s->fds[fd].tmode = "\r\n";
  else if (strstr(buf, "\n"))
    s->fds[fd].tmode = "\n";
  return (str_clean(buf));
}

int		add_buffer(t_buf *buf, t_stck *s, char *src, int len)
{
  t_buf_c	*cur;
  int		size;
  int		i;

  if (!(buf->begin))
    new_buffer(buf, s, len);
  i = -1;
  cur = buf->end;
  size = pow(2, cur->p);
  while (++i < len)
    if (cur->end != size)
      {
	buf->len++;
	cur->s[cur->end] = src[i];
	cur->end++;
      }
    else if (buf->len < buf->max || !buf->max)
      {
	new_buffer(buf, s, len - i--);
	cur = buf->end;
	size = pow(2, cur->p);
      }
  return (0);
}

char		*get_buffer(t_buf *buf, t_stck *s, int fd, int flag)
{
  char		*dest;
  t_buf_c	*cur;
  int		i;

  i = 0;
  dest = Xmalloc(buf->len + 1);
  cur = buf->begin;
  while (cur)
    {
      if (buf->len <= 0)
	break;
      buf->len--;
      dest[i] = cur->s[cur->begin++];
      if (cur->begin >= cur->end)
	{
	  del_buffer(buf, s);
	  cur = buf->begin;
	}
      if (dest[i++] == '\n')
	break;
    }
  if (flag)
    return (select_mode(s, fd, dest));
  return (dest);
}

int		test_buffer(t_buf *buf)
{
  t_buf_c	*cur;
  int		end;
  int		i;

  if (!(cur = buf->begin))
    return (0);
  else if (pow(cur->p, 2) <= 0)
    return (0);
  i = cur->begin;
  end = cur->end;
  while (cur)
    {
      if (cur->s[i++] == '\n')
	return (1);
      if (i >= end)
	{
	  if (!(cur = cur->next))
	    return (0);
	  end = cur->end;
	  i = cur->begin;
	}
    }
  return (0);
}
