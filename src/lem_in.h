/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:41:52 by abaranov          #+#    #+#             */
/*   Updated: 2017/05/15 13:01:47 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H

# define CLEAR 0
# define START 1
# define END 2
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "fcntl.h"
# define BLUE    "\x1B[31m"
# define GREEN  "\x1B[33m"
# define RESET   "\x1b[0m"

int		g_fd;

typedef	struct		s_ants
{
	int					amount_ants;
	struct s_room		*rooms_i;
	struct s_links		*ways;
	struct s_links		*way_temp;
	struct s_room		*res;
}					t_ants;

typedef	struct		s_room
{
	char			*name;
	int				position;
	struct s_links	*links;
	int				visited;
	struct s_room	*next;
}					t_room;

typedef struct		s_links
{
	char			*c_name;
	int				seen;
	int				donotuse;
	int				shortest;
	int				number_of_ant;
	int				len;
	struct s_links	*way;
	struct s_links	*next;
}					t_links;

void				free_array(char **coor);
int					check_spaces(char *line);
int					is_end(t_room *rooms, char *name);
int					is_seen(t_room *rooms, char *name);
void				delete_last(t_links *head);
int					is_intersect(t_links *way1, t_links *way2);
int					same_ways(t_links *way1, t_links *way2);
void				find_end_reset_shortest(t_links **ways);
void				find_end_set_shortest(t_links **ways);
void				move_ants(t_ants **all);
int					chack_start_end(t_room *rooms);
int					handle_start(t_ants **all, t_room **res);
int					handle_end(t_ants **all, t_room **res);
int					isroom(char *line);
int					reading(t_ants **all);
void				write_error();
void				lst_add_rooms(t_room **stk, char *name, int position);
int					amount_list_el_rooms(t_room *list);
int					handle_links(t_ants **all, char *line, t_room **res);
int					rooms_n(t_room *room);
int					is_link(char *line);
void				lst_add_links(t_links **stk, char *connection);
int					start_all(t_ants **all);
int					amount_links(t_links *list);
void				out_res(t_room *res);

#endif
