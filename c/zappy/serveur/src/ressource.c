#include <sys/time.h>
#include <sys/timeb.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "loop.h"
#include "ressource.h"
#include "actions_ia/check_action_ia.h"
#include "transfer/recv.h"
#include "utils/timeout.h"
#include "utils/lib.h"
#include "utils/x.h"

static void	generate_stone(t_stck *s, int stone, int type)
{
  int		i;
  int		j;
  int		*tmp;
  int		nb;

  i = -1;
  nb = 0;
  while (++i < s->map.x)
    {
      j = -1;
      while (++j < s->map.y)
	{
	  if (RANDOM(1, 1000) > 750)
	    {
	      tmp = &(s->map.map[i + j * s->map.x].linemate) + type;
	      (*tmp)++;
	      if (++nb == stone)
		nb = 0;
	    }
	}
    }
}

static void	generate_food(t_stck *s, int need_food, int current_food)
{
  int		i;
  int		j;
  int		rand_nb;

  i = 0;
  while (i <= s->map.x)
    {
      j = 0;
      while (j < s->map.y)
	{
	  rand_nb = RANDOM(0, (s->map.x / 2));
	  if (current_food >= need_food)
	    return ;
	  else if (rand_nb > (s->map.x / 3))
	    {
	      s->map.map[i + j * s->map.x].food++;
	      current_food++;
	    }
	  j++;
	}
      i++;
    }
}

static int	get_map_food(t_stck *s)
{
  int		i;
  int		j;
  int		current_food;

  i = 0;
  current_food = 0;
  while (i < s->map.x)
    {
      j = 0;
      while (j < s->map.y)
	{
	  if (s->map.map[i + j * s->map.x].food > 0)
	    current_food += s->map.map[i + j * s->map.x].food;
	  j++;
	}
      i++;
    }
  return (current_food);
}

void		check_ressource(t_stck *s)
{
  int		food[2];
  int		stone;
  int		type;
  static int	stone_generate;

  type = 0;
  stone = (s->max_tclient / count(s->teams))
    + ((s->map.x + s->map.y) / 100);
  food[NEED] = stone;
  food[NEED] = food[NEED] < 100
    ? (100 * FOOD_INCREASE) : (food[NEED] * FOOD_INCREASE);
  food[CURRENT] = get_map_food(s);
  while (food[CURRENT] < food[NEED])
    {
      generate_food(s, food[NEED], food[CURRENT]);
      food[CURRENT] = get_map_food(s);
    }
  if (!stone_generate)
    {
      stone *= STONE_INCREASE;
      while (type < 6)
	generate_stone(s, stone, type++);
      stone_generate = 1;
    }
}
