#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "global.h"
#include "parse_opt.h"
#include "init.h"
#include "colors.h"
#include "loop.h"
#include "utils/x.h"

int		main(int ac, char **av)
{
  struct rlimit	r;
  t_stck	s;

  memset(&s, 0, sizeof(t_stck));
  X((void *)-1, (void *)getrlimit(RLIMIT_NOFILE, &r), "getrlimit");
  s.lim_fd = r.rlim_cur;
  if (parse_opt(&s, ac, av))
    {
      fprintf(stderr, "synopsis : %s\n", SYNOPSIS);
      return (EXIT_FAILURE);
    }
  init(&s);
  printf(BLUE2"\nInitialisation successful !%s\n\n", DEFAULT);
  return (end(&s, loop(&s)));
}
