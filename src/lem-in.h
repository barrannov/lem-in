#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# define CLEAR 0
# define START 1
# define END 2
# define MARKED 1
# define BUSY 3
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "fcntl.h"


int fd;

typedef struct		s_ants
{
	int amount_ants;
	struct s_room *rooms_info;
}					t_ants;

typedef struct		s_room
{
	char	*name;
	int		position; //0 - normal room, 1 - start_al, 2 - end
	struct 		s_links *links;
	int		ind;
	int mark;
	int visited;
	struct 		s_room *next;
}					t_room;

typedef struct		s_links
{
	char *connection;
	int visited;
	struct 		s_links *next;
}					t_links;

int chack_start_end(t_room *rooms);
int handle_start(t_ants **all, t_room **res);
int handle_end(t_ants **all, t_room **res);
int					is_room(char *line);
int					reading(t_ants **all);
void				write_error();
void				lst_add_rooms(t_room **stk, char *name, int position);
int					amount_list_el_rooms(t_room *list);
int handle_links(t_ants **all, char *line, t_room **res);
int					check_the_same_rooms_names(t_room *room);
int					is_link(char *line);
void				lst_add_links(t_links **stk, char *connection);
int start_al(t_ants **all);

#endif
