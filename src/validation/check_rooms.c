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
		if (temp->position == START)
			st = START;
		if (temp->position == END)
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
	char **arr;

	get_next_line(fd, &line);
	lst_add_rooms(res, line, 0);
	if (!is_room(line))
		return (0);
	arr = ft_strsplit(line, ' ');
	lst_add_rooms(&(*all)->rooms_info, ft_strdup(arr[0]), START);
	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	free(arr);
	return (1);
}

int handle_end(t_ants **all, t_room **res)
{
	char *line;
	char **arr;

	get_next_line(fd, &line);
	lst_add_rooms(res, line, 0);
	if (!is_room(line))
		return (0);
	arr = ft_strsplit(line, ' ');
	lst_add_rooms(&(*all)->rooms_info, ft_strdup(arr[0]), END);
	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	free(arr);
	return (1);
}


int check_spaces(char *line)
{
	int i;
	int s;

	i = 0;
	s = 0;
	while (line[i])
	{
		if(line[i] == ' ')
			s++;
		i++;
	}
	return (s);
}

int is_room(char *line)
{
	char **coor_of_rooms;
	int tir;
	int i;

	tir = 0;
	i = 0;
	coor_of_rooms = ft_strsplit(line, ' ');

	tir = 0;
	while (coor_of_rooms[0][tir])
	{
		if (coor_of_rooms[0][tir] == '-')
		{
			while (coor_of_rooms[i])
			{
				free(coor_of_rooms[i]);
				i++;
			}
			free(coor_of_rooms);
			return (0);
		}
		tir++;
	}

	if (!is_number(coor_of_rooms[1]) || !is_number(coor_of_rooms[2])
		|| (coor_of_rooms[0][0] == '#' || coor_of_rooms[0][0] == 'L')
		||  (ft_atoi(coor_of_rooms[1]) > 2147483647 || ft_atoi(coor_of_rooms[2]) > 2147483647)
		|| (length((void *) coor_of_rooms) != 3) || (check_spaces(line) != 2))
	{
		while (coor_of_rooms[i])
		{
			free(coor_of_rooms[i]);
			i++;
		}
		free(coor_of_rooms);

		return (0);
	}

//	while (*(coor_of_rooms++))
//		free(*coor_of_rooms);

	while (coor_of_rooms[i])
	{
		free(coor_of_rooms[i]);
		i++;
	}
	free(coor_of_rooms);
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