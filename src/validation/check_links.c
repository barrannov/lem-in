/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:47:31 by abaranov          #+#    #+#             */
/*   Updated: 2017/05/13 19:54:32 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int					check_the_same_links(t_links *links, char *line)
{
	t_links		*temp;

	if (links == NULL)
		return (1);
	temp = links;
	while (temp)
	{
		if (temp->c_name && ft_strcmp(temp->c_name, line) == 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void				add_link_to_room(t_room **rooms, char *line)
{
	char		**coor_of_links;
	t_room		*temp;
	int			i;

	temp = *rooms;
	coor_of_links = ft_strsplit(line, '-');
	while (temp)
	{
		if (ft_strcmp(coor_of_links[0], temp->name) == 0 &&
				check_the_same_links((temp)->links, coor_of_links[1]))
			lst_add_links(&(temp)->links, ft_strdup(coor_of_links[1]));
		if (ft_strcmp(coor_of_links[1], temp->name) == 0 &&
				check_the_same_links((temp)->links, coor_of_links[0]))
			lst_add_links(&(temp)->links, ft_strdup(coor_of_links[0]));
		temp = temp->next;
	}
	i = 0;
	while (coor_of_links[i])
	{
		free(coor_of_links[i]);
		i++;
	}
	free(coor_of_links);
}

int					check_links_concurrences(t_ants *all, char *line)
{
	char	**coor_of_links;
	t_room	*temp;
	int		f_room1;
	int		f_room2;
	int		i;

	f_room1 = 0;
	f_room2 = 0;
	coor_of_links = ft_strsplit(line, '-');
	temp = all->rooms_i;
	while (temp)
	{
		if (ft_strcmp(coor_of_links[0], temp->name) == 0)
			f_room1 = 1;
		if (ft_strcmp(coor_of_links[1], temp->name) == 0)
			f_room2 = 1;
		temp = temp->next;
	}
	i = 0;
	while (coor_of_links[i])
		free(coor_of_links[i++]);
	free(coor_of_links);
	if (f_room1 == 1 && f_room2 == 1)
		return (1);
	return (0);
}

int					is_link(char *line)
{
	int		i;
	int		l;
	char	**coor_of_links;

	coor_of_links = ft_strsplit(line, '-');
	l = 0;
	i = 0;
	if (length((void *)coor_of_links) == 2)
		while (line[i])
		{
			if (line[i] == '-')
				l++;
			i++;
		}
	i = 0;
	while (coor_of_links[i])
		free(coor_of_links[i++]);
	free(coor_of_links);
	if (l == 1)
		return (1);
	return (0);
}

int					handle_links(t_ants **all, char *line, t_room **res)
{
	if (!rooms_n((*all)->rooms_i)
		|| !chack_start_end((*all)->rooms_i))
		return (0);
	if (!check_links_concurrences(*all, line))
		return (0);
	add_link_to_room(&(*all)->rooms_i, line);
	while (get_next_line(g_fd, &line) > 0)
	{
		lst_add_rooms(res, line, 0);
		if (line[0] == '#')
			continue;
		if (!is_link(line))
			return (0);
		if (!check_links_concurrences(*all, line))
			return (0);
		add_link_to_room(&(*all)->rooms_i, line);
	}
	free(line);
	return (1);
}
