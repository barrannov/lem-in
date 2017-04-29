#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "fcntl.h"

int ix;

typedef struct		s_ants
{
	int amount_ants;
	struct s_room *rooms_info;
	int *asarray; // Ассоциативный массив
}					t_ants;

typedef struct		s_room
{
	char	*name;
	int		position; //0 - normal room, 1 - start, 2 - end
	int		ind;
	struct 		s_room *next;
}					t_room;

int fd;

int					reading(t_ants **all);
void				write_error();
void lst_add(t_room **stk, char *name, int position);
int					amount_list_el(t_room *list);

#endif
