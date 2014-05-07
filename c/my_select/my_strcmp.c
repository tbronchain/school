#include <unistd.h>
#include "my_select.h"

int	my_strcmp(char *s1, char *s2)
{
  int	var;

  var = 0;
  while (s1[var] == s2[var])
    {
      if (s1[var] > s2[var])
	return (0);
      if (s1[var] < s2[var])
	return (0);
      if (s1[var] == s2[var] && s2[var] == '\0')
	return (1);
      var++;
    }
  if (var > 0)
    if (s1[var - 1] == s2[var - 1] && s2[var] == '\0')
      return (1);
  if (s1[var] > s2[var])
    return (0);
  if (s1[var] < s2[var])
    return (0);
  if (s1[var] == s2[var] && s2[var] == '\0')
    return (1);
  return (0);
}
