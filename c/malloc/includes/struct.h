#ifndef STRUCT_H_
# define STRUCT_H_

/* STRUCTURES */

typedef	struct			s_block_descriptor
{
  unsigned int			p;
  struct s_block_descriptor	*next;
  struct s_block_descriptor	*prev;
}				t_bd;

/* DEFINES */

#define SIZE_BD sizeof(t_bd)

/* GLOBALS */

t_bd	*gl_alloc;
t_bd	*buckets[32];

/* SYSTEM PROTOTYPES */

void	*sbrk(int increment);


#endif /* !STRUCT_H_ */
