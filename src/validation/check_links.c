# include "../lem-in.h"

void out_links(t_room *res)
{
	t_room *temp_res;
	t_links *temp;

	temp_res = res;
	while (temp_res)
	{
		ft_putstr(temp_res->name);
		ft_putstr(" links with:\n");
		temp = temp_res->links;
		ft_putchar('[');
		while (temp)
		{
			ft_putstr(temp->connection);
			if (temp->next)
				ft_putstr(", ");
			temp = temp->next;
		}
		ft_putchar(']');
		ft_putstr("\n");
		temp_res = temp_res->next;
	}
	ft_putstr("\n");
}

int check_the_same_links(t_links *links, char *line)
{
	t_links *temp;

	if (links == NULL)
		return (1);
	temp = links;
	while (temp)
	{
		if (temp->connection && ft_strcmp(temp->connection, line) == 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void add_link_to_room(t_room **rooms, char *line)
{
	char **coor_of_links;
	t_room *temp;

	temp = *rooms;
	coor_of_links = ft_strsplit(line, '-');
	while (temp->next)
	{
		if (ft_strcmp(coor_of_links[0], temp->name) == 0 && check_the_same_links((temp)->links, coor_of_links[1]))
			lst_add_links(&(temp)->links, ft_strdup(coor_of_links[1]));
		if (ft_strcmp(coor_of_links[1], temp->name) == 0 && check_the_same_links((temp)->links, coor_of_links[0]))
			lst_add_links(&(temp)->links, ft_strdup(coor_of_links[0]));
		temp = temp->next;
	}
	int i;

	i = 0;
	while (coor_of_links[i])
	{
		free(coor_of_links[i]);
		i++;
	}
	free(coor_of_links);
}

int check_links_concurrences(t_ants *all, char *line)
{
	char **coor_of_links;
	t_room *temp;
	int f_room1;
	int f_room2;

	f_room1 = 0;
	f_room2 = 0;
	coor_of_links = ft_strsplit(line, '-');
//Поверяю линкуется ли комната сама с собой
//	if (ft_strcmp(coor_of_links[0], coor_of_links[1]) == 0)
//		return (0);
	temp = all->rooms_info;
	while (temp)
	{
		if (ft_strcmp(coor_of_links[0], temp->name) == 0)
			f_room1 = 1;
		if (ft_strcmp(coor_of_links[1], temp->name) == 0)
			f_room2 = 1;
		temp = temp->next;
	}
	int i;

	i = 0;
	while (coor_of_links[i])
	{
		free(coor_of_links[i]);
		i++;
	}
	free(coor_of_links);
	if (f_room1 == 1 && f_room2 == 1)
		return (1);
	else
		return (0);
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
	{
		i = 0;
		while (coor_of_links[i])
		{
			free(coor_of_links[i]);
			i++;
		}
		free(coor_of_links);
		return (0);
	}
	while (line[i])
	{
		if (line[i] == '-')
			l++;
		i++;
	}
	i = 0;
	while (coor_of_links[i])
	{
		free(coor_of_links[i]);
		i++;
	}
	free(coor_of_links);
	if (l == 1)
		return (1);
	else
		return (0);
}


int handle_links(t_ants **all, char *line, t_room **res)
{
	if (!check_the_same_rooms_names((*all)->rooms_info)
		|| !chack_start_end((*all)->rooms_info))
		return (0);
	if (!check_links_concurrences(*all, line))
		return (0);
	add_link_to_room(&(*all)->rooms_info, line);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '#')
			continue;
		if (!is_link(line))
			return (0);
		if (!check_links_concurrences(*all, line))
			return (0);
		lst_add_rooms(res, line, 0);
		add_link_to_room(&(*all)->rooms_info, line);
	}
	free(line);
//	out_links((*all)->rooms_info);
	return (1);
}

