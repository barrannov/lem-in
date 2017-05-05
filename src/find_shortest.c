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


//int is_end_exist(t_room *rooms, char *name)
//{
//	t_room *temp;
//
//	temp = rooms;
//	while (temp)
//	{
//		if (ft_strcmp(temp->name, name) == 0 && temp->position == END)
//			return (1);
//		temp = temp->next;
//	}
//	return (0);
//}

void delete_last(t_links *head)
{
	t_links *temp = head;
	t_links *t;

	while (temp->next != NULL)
	{
		t = temp;
		temp = temp->next;
	}
	free(t->next);
	t->next = NULL;
}

int is_intersect(t_ants **all, t_links *way)
{
	t_links *temp_way_check; //Way to check
	t_links *temp_way_main; //Main list with all ways
	t_links *temp_way_under; //Way in main list

	temp_way_check = way;
	while (temp_way_check)
	{
		temp_way_main = (*all)->ways;
		while (temp_way_main)
		{
			temp_way_under = temp_way_main->way;
			while (temp_way_under)
			{
				if(!ft_strcmp(temp_way_check->connection, temp_way_under->connection)
						&& !is_end((*all)->rooms_info,  temp_way_under->connection)
						&& !is_start((*all)->rooms_info,  temp_way_under->connection))
					if(amount_list_el_links(temp_way_check) < amount_list_el_links(temp_way_under))
					{

					}
				temp_way_under = temp_way_under->next;
			}
			temp_way_main = temp_way_main->way;
		}
		temp_way_check = temp_way_check->next;
	}
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

int algorithm(char *name, t_ants **all, t_links *way_temp)
{
	t_room *temp_room;
	t_links *temp_links;

	lst_add_links(&way_temp, name);
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
				algorithm(temp_links->connection, all, way_temp);
			}
			temp_links->visited = 0;
			temp_links = temp_links->next;
		}
		temp_room->visited = 0;
	}
	handle_way(all, way_temp);
	delete_last(way_temp);
	return (1);
}

int start_al(t_ants **all)
{
	t_room *temp;
	t_links *way_temp;

	way_temp = NULL;
	(*all)->ways = NULL;
	temp = (*all)->rooms_info;
	while (temp->position != START)
		temp = temp->next;
	algorithm(temp->name, all, way_temp);
	return (1);
}