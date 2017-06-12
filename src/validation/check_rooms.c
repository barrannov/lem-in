/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:06:02 by abaranov          #+#    #+#             */
/*   Updated: 2017/05/15 14:00:48 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int					handle_start(t_ants **all, t_room **res)
{
	char	*line;
	char	**arr;

	get_next_line(g_fd, &line);
	lst_add_rooms(res, line, 0);
	if (!isroom(line))
		return (0);
	arr = ft_strsplit(line, ' ');
	lst_add_rooms(&(*all)->rooms_i, ft_strdup(arr[0]), START);
	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	free(arr);
	return (1);
}

int					handle_end(t_ants **all, t_room **res)
{
	char	*line;
	char	**arr;

	get_next_line(g_fd, &line);
	lst_add_rooms(res, line, 0);
	if (!isroom(line))
		return (0);
	arr = ft_strsplit(line, ' ');
	lst_add_rooms(&(*all)->rooms_i, ft_strdup(arr[0]), END);
	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	free(arr);
	return (1);
}

void				free_array(char **coor)
{
	int i;

	i = 0;
	while (coor[i])
		free(coor[i++]);
	free(coor);
}

int					isroom(char *line)
{
	char	**coor;
	int		tir;
	int		f;

	f = 1;
	coor = ft_strsplit(line, ' ');
	tir = 0;
	if (length((void *)coor) != 3)
	{
		free_array(coor);
		return (0);
	}
	while (coor[0][tir])
		if (coor[0][tir++] == '-')
		{
			free_array(coor);
			return (0);
		}
	if ((!is_number(coor[1]) || !is_number(coor[2]))
			|| (coor[0][0] == '#' || coor[0][0] == 'L')
			|| (ft_atoi(coor[1]) > 2147483647 || ft_atoi(coor[2]) > 2147483647)
			|| (length((void *)coor) != 3) || (check_spaces(line) != 2))
		f = 0;
	free_array(coor);
	return (f);
}

int					rooms_n(t_room *room)
{
	t_room		*temp;
	t_room		*temp_loop;
	int			i;
	int			j;

	i = 0;
	temp = room;
	if (amount_list_el_rooms(room) >= 2)
		while (temp)
		{
			temp_loop = room;
			j = 0;
			while (temp_loop)
			{
				if (((!ft_strcmp(temp_loop->name, temp->name)) ||
							((temp_loop->position == 2 && temp->position == 2)
			|| (temp_loop->position == 1 && temp->position == 1))) && j != i)
					return (0);
				temp_loop = temp_loop->next;
				j++;
			}
			temp = temp->next;
			i++;
		}
	return (1);
}
