/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:26:59 by abaranov          #+#    #+#             */
/*   Updated: 2017/05/13 17:27:00 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int				is_end(t_room *rooms, char *name)
{
	t_room		*temp;

	temp = rooms;
	while (temp)
	{
		if (ft_strcmp(temp->name, name) == 0 && temp->position == END)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int				is_visited(t_room *rooms, char *name)
{
	t_room		*temp;

	temp = rooms;
	while (temp)
	{
		if (ft_strcmp(temp->name, name) == 0 && temp->visited == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void		delete_last(t_links *head)
{
	t_links *temp;
	t_links *t;

	temp = head;
	while (temp->next != NULL)
	{
		t = temp;
		temp = temp->next;
	}
	free(t->next);
	t->next = NULL;
}

int			is_intersect(t_links *way1, t_links *way2)
{
	t_links *way1_temp;
	t_links *way2_temp;

	way1_temp = way1;
	way1_temp = way1_temp->next;
	while (way1_temp->next)
	{
		way2_temp = way2->next;
		while (way2_temp->next)
		{
			if (ft_strcmp(way1_temp->connection, way2_temp->connection) == 0)
				return (1);
			way2_temp = way2_temp->next;
		}
		way1_temp = way1_temp->next;
	}

	return (0);
}

int			same_ways(t_links *way1, t_links *way2)
{
	t_links *way1_temp;
	t_links *way2_temp;

	way1_temp = way1;
	way2_temp = way2;
	while (way1_temp && way2_temp)
	{
		if (ft_strcmp(way1_temp->connection, way2_temp->connection) != 0)
			return (0);
		way1_temp = way1_temp->next;
		way2_temp = way2_temp->next;
	}
	return (1);
}


int				delete_intersect(t_links **ways)
{
	t_links 	*ways_temp;
	t_links		*ways_temp2;
	t_links 	*w_temp;

	ways_temp = *ways;
	while ((ways_temp) != NULL)
	{
		w_temp = (ways_temp)->way;
		ways_temp2 = *ways;
		while ((ways_temp2) != NULL)
		{
			if (!same_ways((w_temp), (ways_temp2)->way) && is_intersect((w_temp), (ways_temp2)->way))
			{
				if (amount_list_el_links((w_temp)) == amount_list_el_links((ways_temp2)->way) &&
					(ways_temp2)->donotuse != 1)
					ways_temp->donotuse = 1;
				if (amount_list_el_links((w_temp)) < amount_list_el_links((ways_temp2)->way))
					ways_temp2->donotuse = 1;
			}
			ways_temp2 = (ways_temp2)->next;
		}
		ways_temp = (ways_temp)->next;
	}
	return (1);
}

int handle_way(t_ants **all, t_links *way_temp)
{
	t_links *temp;
	t_links *ways_temp_all;

	temp = way_temp;
	while (temp->next)
		temp = temp->next;
	if (!is_end((*all)->rooms_info, temp->connection))
		return (0);
	temp = way_temp;
	lst_add_links(&(*all)->ways, "");
	ways_temp_all = (*all)->ways;
	while (ways_temp_all->next)
		ways_temp_all = ways_temp_all->next;
	while (temp)
	{
		lst_add_links(&ways_temp_all->way, temp->connection);
		temp = temp->next;
	}
	return (0);
}

void algorithm(char *name, t_ants **all, int f)
{
	t_room *temp_room;
	t_links *temp_links;

	lst_add_links(&(*all)->way_temp, name);
	temp_room = (*all)->rooms_info;
	if (!is_end((*all)->rooms_info, name))
	{
		while (ft_strcmp(temp_room->name, name) != 0)
			temp_room = temp_room->next;
		temp_room->visited = 1;
		temp_links = temp_room->links;
		while (temp_links)
		{
			if (temp_links->visited != 1 && !is_visited((*all)->rooms_info, temp_links->connection))
			{
				temp_links->visited = 1;
				algorithm(temp_links->connection, all, f++);
			}
			temp_links->visited = 0;
			temp_links = temp_links->next;
		}
		temp_room->visited = 0;
	}
	handle_way(all, (*all)->way_temp);
	delete_last((*all)->way_temp);
}



void set_len(t_links **ways)
{
	t_links *ways_temp;

	ways_temp = *ways;
	while (ways_temp)
	{
		ways_temp->len = amount_list_el_links(ways_temp->way);
		ways_temp = ways_temp->next;
	}
}

int start_all(t_ants **all)
{
	t_room *temp;


	(*all)->way_temp = NULL;
	temp = (*all)->rooms_info;
	while (temp->position != START)
		temp = temp->next;
	algorithm(temp->name, all,  0);
	delete_intersect(&(*all)->ways);
	set_len(&(*all)->ways);
	return (1);
}
