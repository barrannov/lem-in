/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:26:59 by abaranov          #+#    #+#             */
/*   Updated: 2017/05/15 13:17:21 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int					delete_intersect(t_links **ways)
{
	t_links		*ways_temp;
	t_links		*ways_temp2;
	t_links		*w_temp;

	ways_temp = *ways;
	while ((ways_temp) != NULL)
	{
		w_temp = (ways_temp)->way;
		ways_temp2 = *ways;
		while ((ways_temp2) != NULL)
		{
			if (!same_ways((w_temp), (ways_temp2)->way)
				&& is_intersect((w_temp), (ways_temp2)->way))
			{
				if (amount_links((w_temp)) < amount_links((ways_temp2)->way))
					ways_temp2->donotuse = 1;
				if (amount_links((w_temp)) == amount_links((ways_temp2)->way) &&
					(ways_temp2)->donotuse != 1)
					ways_temp->donotuse = 1;
			}
			ways_temp2 = (ways_temp2)->next;
		}
		ways_temp = (ways_temp)->next;
	}
	return (1);
}

int					handle_way(t_ants **all, t_links *way_temp)
{
	t_links		*temp;
	t_links		*ways_temp_all;

	temp = way_temp;
	while (temp->next)
		temp = temp->next;
	if (!is_end((*all)->rooms_i, temp->c_name))
		return (0);
	temp = way_temp;
	lst_add_links(&(*all)->ways, "");
	ways_temp_all = (*all)->ways;
	while (ways_temp_all->next)
		ways_temp_all = ways_temp_all->next;
	while (temp)
	{
		lst_add_links(&ways_temp_all->way, temp->c_name);
		temp = temp->next;
	}
	return (0);
}

void				algorithm(char *name, t_ants **all)
{
	t_room		*temp_room;
	t_links		*tlinks;

	lst_add_links(&(*all)->way_temp, name);
	temp_room = (*all)->rooms_i;
	if (!is_end((*all)->rooms_i, name))
	{
		while (ft_strcmp(temp_room->name, name) != 0)
			temp_room = temp_room->next;
		temp_room->visited = 1;
		tlinks = temp_room->links;
		while (tlinks)
		{
			if (!tlinks->seen && !is_seen((*all)->rooms_i, tlinks->c_name))
			{
				tlinks->seen = 1;
				algorithm(tlinks->c_name, all);
			}
			tlinks->seen = 0;
			tlinks = tlinks->next;
		}
		temp_room->visited = 0;
	}
	handle_way(all, (*all)->way_temp);
	delete_last((*all)->way_temp);
}

void				set_len(t_links **ways)
{
	t_links		*ways_temp;

	ways_temp = *ways;
	while (ways_temp)
	{
		ways_temp->len = amount_links(ways_temp->way);
		ways_temp = ways_temp->next;
	}
}

int					start_all(t_ants **all)
{
	t_room		*temp;

	(*all)->way_temp = NULL;
	temp = (*all)->rooms_i;
	while (temp->position != START && temp->next)
		temp = temp->next;
	algorithm(temp->name, all);
	delete_intersect(&(*all)->ways);
	set_len(&(*all)->ways);
	return (1);
}
