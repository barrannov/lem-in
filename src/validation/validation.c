/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:41:46 by abaranov          #+#    #+#             */
/*   Updated: 2017/05/13 18:41:47 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void				out_res(t_room *res)
{
	t_room *temp;

	temp = res;
	while (temp)
	{
		ft_putstr(temp->name);
		free(temp->name);
		free(temp);
		ft_putstr("\n");
		temp = temp->next;
	}
}

void				for_less(char **arr, char *line, t_ants **all)
{
	arr = ft_strsplit(line, ' ');
	lst_add_rooms(&(*all)->rooms_i, ft_strdup(arr[0]), CLEAR);
	free_array(arr);
}

int					continue_read(t_ants **all, char *line, char **arr)
{
	while (get_next_line(g_fd, &line) > 0)
	{
		lst_add_rooms(&(*all)->res, line, 0);
		if (!ft_strcmp("##start", line))
		{
			if (!handle_start(all, &(*all)->res))
				return (0);
		}
		else if (!ft_strcmp("##end", line))
		{
			if (!handle_end(all, &(*all)->res))
				return (0);
		}
		else if (line[0] != '#' && (isroom(line) && rooms_n((*all)->rooms_i)))
			for_less(arr, line, all);
		else if (line[0] != '#' && (is_link(line)))
		{
			if (!handle_links(all, line, &(*all)->res))
				return (0);
		}
		else if (line[0] != '#')
			return (0);
	}
	free(line);
	return (1);
}

int					reading(t_ants **all)
{
	char		*line;
	char		**arr;

	arr = NULL;
	g_fd = 0;
	get_next_line(g_fd, &line);
	lst_add_rooms(&(*all)->res, line, 0);
	while (line[0] == '#')
	{
		get_next_line(g_fd, &line);
		lst_add_rooms(&(*all)->res, line, 0);
	}
	if (is_number(line) && ft_atoi(line) > 0 && ft_atoi(line) < 2147483647)
		(*all)->amount_ants = (int)ft_atoi(line);
	else
		return (0);
	(*all)->rooms_i = NULL;
	if (continue_read(all, line, arr) == 0)
		return (0);
	start_all(all);
	return (1);
}
