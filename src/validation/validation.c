#include "../lem-in.h"

int is_room(char *line)
{
	char **coor_of_rooms;
	int tir;

	tir = 0;
	coor_of_rooms = ft_strsplit(line, ' ');
	if (length((void *) coor_of_rooms) != 3)
		return (0);
	while (coor_of_rooms[0][tir])
	{
		if (coor_of_rooms[0][tir] == '-')
			return (0);
		tir++;
	}
	if (coor_of_rooms[0][0] == '#' || coor_of_rooms[0][0] == 'L')
		return (0);
	if (!is_number(coor_of_rooms[1]) || !is_number(coor_of_rooms[2]))
		return (0);
	return (1);
}

int handle_start(t_ants **all)
{
	char *line;

	get_next_line(fd, &line);
	if (!is_room(line))
		return (0);
	lst_add(&(*all)->rooms_info, ft_strsplit(line, ' ')[0], 1);
	return (1);
}

int handle_end(t_ants **all)
{
	char *line;

	get_next_line(fd, &line);
	if (!is_room(line))
		return (0);
	lst_add(&(*all)->rooms_info, ft_strsplit(line, ' ')[0], 2);
	return (1);
}

int check_the_same(t_room *room)
{
	t_room *temp;
	t_room *temp_loop;
	int		i;
	int		j;

	i = 0;
	temp = room;
	if(amount_list_el(room) < 2)
		return (1);
	while (temp->next)
	{
		temp_loop = room;
		j = 0;
		while (temp_loop->next)
		{
			if(((!ft_strcmp(temp_loop->name, temp->name)) ||
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

int is_link(char *line)
{
	int i;
	int l;
	char **coor_of_links;

	coor_of_links = ft_strsplit(line, '-');
	l = 0;
	i = 0;
	if (length((void *) coor_of_links) != 2)
		return (0);
	while (line[i])
	{
		if (line[i] == '-')
			l++;
		i++;
	}
	if (l == 1)
		return (1);
	else
		return (0);
}

int reading(t_ants **all)
{
	char *line;
	int i;

	fd = open("/nfs/2016/a/abaranov/projects/lem-in/src/validation/test", O_RDONLY);
	i = 0;
	get_next_line(fd, &line);
	ix = 0;
	if (is_number(line))
		(*all)->amount_ants = ft_atoi(line);
	else
		return (0);
	(*all)->rooms_info = NULL;
	//ft_putnbr((*all)->amount_ants);
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strcmp("##start", line))
		{
			if (!handle_start(all))
				return (0);
		}
		else if (!ft_strcmp("##end", line))
		{
			if (!handle_end(all))
				return (0);
		}
		else if (is_room(line) || check_the_same((*all)->rooms_info))
			lst_add(&(*all)->rooms_info, ft_strsplit(line, ' ')[0], 0);
		else if (line[0] == '#')
			continue;
		else if (!is_link(line))
			;
		else
			return (0);
		if(!check_the_same((*all)->rooms_info))
			return (0);
		i++;
	}
	return (1);
}
