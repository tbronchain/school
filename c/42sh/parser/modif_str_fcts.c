#include <strings.h>
#include "modif_str_fcts.h"
#include "count_fcts.h"
#include "x_function.h"

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*tmp;

  tmp = xmalloc(sizeof(*tmp) * (my_strlen(str1) + my_strlen(str2) + 1));
  i = 0;
  while (str1[i] != '\0')
    {
      tmp[i] = str1[i];
      i++;
    }
  j = 0;
  while (str2[j] != '\0')
    {
      tmp[i + j] = str2[j];
      j++;
    }
  tmp[i + j] = '\0';
  return (tmp);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdcpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[n] != '\0')
    dest[i++] = src[n++];
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *str)
{
  char	*res;
  int	str_len;

  str_len = my_strlen(str);
  res = xmalloc(sizeof(*res) * (str_len + 1));
  bzero(res, str_len + 1);
  my_strcpy(res, str);
  return (res);
}

char	*my_nstrcpy(char *dest, char *src, int y)
{
  int	i;

  i = 0;
  while (src[y] != '\0')
    {
      dest[i] = src[y];
      i++;
      y++;
    }
  dest[i] = src[y];
  return (dest);
}
