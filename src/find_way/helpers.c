#include "../lem-in.h"

int					is_end(t_room *rooms, char *name)
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

int					is_visited(t_room *rooms, char *name)
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

void				delete_last(t_links *head)
{
	t_links		*temp;
	t_links		*t;

	temp = head;
	while (temp->next != NULL)
	{
		t = temp;
		temp = temp->next;
	}
	free(t->next);
	t->next = NULL;
}

int					is_intersect(t_links *way1, t_links *way2)
{
	t_links		*way1_temp;
	t_links		*way2_temp;

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

int					same_ways(t_links *way1, t_links *way2)
{
	t_links		*way1_temp;
	t_links		*way2_temp;

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