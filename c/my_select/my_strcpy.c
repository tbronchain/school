#include "my_select.h"

char	*my_strcpy(char *dest, char *src)
{
  int	var;

  var = 0;
  while (src[var] != '\0')
    {
      dest[var] = src[var];
      var = var + 1;
    }
  dest[var] = '\0';
  return (dest);
}
