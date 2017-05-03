#include "lem-in.h"

int check_link_as_marked(t_room **room, t_links *links)
{
	t_room *temp;

	temp = *room;
	while (ft_strcmp(temp->name, links->connection) != 0)
	{
		temp = temp->next;
	}
	if (temp->mark == MARKED)
		return (0);
	else
	{
		temp->mark = MARKED;
		return (1);
	}
}

int is_start(t_room *rooms, char *name)
{
	t_room *temp;

	temp = rooms;
	while (temp)
	{
		if (ft_strcmp(temp->name, name) == 0 && temp->position == START)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int is_end(t_room *rooms, char *name)
{
	t_room *temp;

	temp = rooms;
	while (temp)
	{
		if (ft_strcmp(temp->name, name) == 0 && temp->position == END)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int is_visited(t_room *rooms, char *name)
{
	t_room *temp;

	temp = rooms;
	while (temp)
	{
		if (ft_strcmp(temp->name, name) == 0 && temp->visited == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int algorithm(char *name, t_ants **all, int ind)
{
	t_room *temp_room;
	t_links *temp_links;

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
				algorithm(temp_links->connection, all, 0);
			}
			temp_links->visited = 0;
			temp_links = temp_links->next;
		}
		temp_room->visited = 0;
	}
//	t_room *temp;
//	t_links *temp_lins;
//	t_room *room;
//
//	room = (*all)->rooms_info;
//	temp = (*all)->rooms_info;
//	while (ft_strcmp(temp->name, name) == 1)
//		temp = temp->next;
//	temp_lins = temp->links;
//	while (temp_lins)
//	{
//		if (check_link_as_marked(&room, temp_lins))
//		{
//
//		}
//		temp_lins = temp_lins->next;
//	}
	return (1);
}

int start_al(t_ants **all)
{
	t_room *temp;

	temp = (*all)->rooms_info;
	while (temp->position != START)
	{
		temp = temp->next;
	}
	algorithm(temp->name, all, 0);
	return (1);
}