# include "../lem-in.h"

int chack_start_end(t_room *rooms)
{
	t_room *temp;
	int st;
	int end;

	st = 0;
	end = 0;
	temp = rooms;
	while (temp)
	{
		if(temp->position == START)
			st = START;
		if(temp->position == END)
			end = END;
		temp = temp->next;
	}
	if (st == START && end == END)
		return (1);
	else
		return (0);
}

int handle_start(t_ants **all, t_room **res)
{
	char *line;

	get_next_line(fd, &line);
	lst_add_rooms(res, line, 0);
	if (!is_room(line))
		return (0);
	lst_add_rooms(&(*all)->rooms_info, ft_strsplit(line, ' ')[0], START);
	return (1);
}

int handle_end(t_ants **all, t_room **res)
{
	char *line;

	get_next_line(fd, &line);
	lst_add_rooms(res, line, 0);
	if (!is_room(line))
		return (0);
	lst_add_rooms(&(*all)->rooms_info, ft_strsplit(line, ' ')[0], END);
	return (1);
}

int is_room(char *line)
{
	char **coor_of_rooms;
	int tir;
	int i;
	int spaces;

	i = -1;
//	while(line[i++])
//	{
//		if()
//	}
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
	if (ft_atoi(coor_of_rooms[1]) > 2147483647 || ft_atoi(coor_of_rooms[2]) > 2147483647)
		return (0);
	if (coor_of_rooms[0][0] == '#' || coor_of_rooms[0][0] == 'L')
		return (0);
	if (!is_number(coor_of_rooms[1]) || !is_number(coor_of_rooms[2]))
		return (0);
	return (1);
}

int check_the_same_rooms_names(t_room *room)
{
	t_room *temp;
	t_room *temp_loop;
	int i;
	int j;

	i = 0;
	temp = room;
	if (amount_list_el_rooms(room) < 2)
		return (1);
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