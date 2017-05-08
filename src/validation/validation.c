# include "../lem-in.h"

void out_res(t_room *res)
{
	t_room *temp;

	temp = res;
	while (temp)
	{
		ft_putstr(temp->name);
		ft_putstr("\n");
		temp = temp->next;
	}
}

int reading(t_ants **all)
{
	char *line;
	int i;
	t_room *res;

	fd = open("/nfs/2016/a/abaranov/projects/lem-in/src/validation/test", O_RDONLY);
	i = 0;
	get_next_line(fd, &line);
	lst_add_rooms(&res, line, 0);
	while (line[0] == '#')
	{
		get_next_line(fd, &line);
		lst_add_rooms(&res, line, 0);
	}

	if (is_number(line) && ft_atoi(line) > 0 && ft_atoi(line) < 2147483647)
		(*all)->amount_ants = (int)ft_atoi(line);
	else
		return (0);
	(*all)->rooms_info = NULL;
	//ft_putnbr((*all)->amount_ants);
	while (get_next_line(fd, &line) > 0)
	{
		lst_add_rooms(&res, line, 0);
		if (!ft_strcmp("##start", line))
		{
			if (!handle_start(all, &res))
				return (0);
		}
		else if (!ft_strcmp("##end", line))
		{
			if (!handle_end(all, &res))
				return (0);
		}
		else if (is_room(line) && check_the_same_rooms_names((*all)->rooms_info))
			lst_add_rooms(&(*all)->rooms_info, ft_strsplit(line, ' ')[0], CLEAR);
		else if (line[0] == '#')
			continue;
		else if (is_link(line))
		{
			if (!handle_links(all, line, &res))
				return (0);
		}
		else
			return (0);
		i++;
	}
	out_res(res);
	start_all(all);
	return (1);
}