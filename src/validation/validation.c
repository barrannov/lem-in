#include "../lem-in.h"

int is_room(char *line)
{
	char **coor_of_rooms;
	int i;

	i = 0;
	coor_of_rooms = ft_strsplit(line, ' ');
	while (coor_of_rooms[i])
		i++;
	if (i != 3)
		return (0);
	if (coor_of_rooms[0][0] == '#')
		return (0);
	if (!is_number(coor_of_rooms[1]) || !is_number(coor_of_rooms[1]))
		return (0);
	return (1);
}

int handle_start(t_ants **all)
{
	char *line;

	get_next_line(0, &line);
	if (!is_room(line))
		return (0);
	lst_add(&(*all)->rooms_info, ft_strsplit(line, ' ')[0], 1);
	return (1);
}

int handle_end(t_ants **all)
{
	char *line;

	get_next_line(0, &line);
	if (!is_room(line))
		return (0);
	lst_add(&(*all)->rooms_info, ft_strsplit(line, ' ')[0], 2);
	return (1);
}

int reading(t_ants **all)
{
	int y;
	int x;
	char *line;
	int i;

	i = 0;
	y = 0;
	get_next_line(0, &line);

	if (is_number(line))
		(*all)->amount_ants = ft_atoi(line);
	else
		return (0);
	//ft_putnbr((*all)->amount_ants);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp("##start", line) && !handle_start(all))
		{
			return (0);
		}
		else if (!ft_strcmp("##end", line) && !handle_end(all))
		{
			return (0);
		}
		else if (is_room(line))
			lst_add(&(*all)->rooms_info, ft_strsplit(line, ' ')[0], 0);
		else
			return (0);
		i++;
	}
	return (1);
}