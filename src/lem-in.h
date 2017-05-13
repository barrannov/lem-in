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
	struct 		s_links *ways;
	struct 		s_links *way_temp;
	struct 		 s_room *res;
	t_list *map;
}					t_ants;

typedef struct		s_room
{
	char	*name;
	int		position; //0 - normal room, 1 - start_al, 2 - end
	struct 		s_links *links;
	int visited;
	struct 		 s_room *next;
}					t_room;

typedef struct		s_links
{
	char *connection;
	int visited;
	int donotuse;
	int shortest;
	int busy;
	int number_of_ant;
	int	len;
	struct 		s_links *way;
	struct 		s_links *next;
}					t_links;

int					is_end(t_room *rooms, char *name);
int					is_visited(t_room *rooms, char *name);
void				delete_last(t_links *head);
int					is_intersect(t_links *way1, t_links *way2);
int					same_ways(t_links *way1, t_links *way2);
void find_end_reset_shortest(t_links **ways);
void find_end_set_shortest(t_links **ways);
void move_ants(t_ants **all);
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
int start_all(t_ants **all);
int					amount_links(t_links *list);
void ft_del_list(t_links **head);
void ft_del_list_room(t_room **head);
void out_res(t_room *res);

#endif
