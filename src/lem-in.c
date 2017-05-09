#include "lem-in.h"

int out_ways(t_links *ways)
{
	t_links *ways_temp;
	t_links *w_temp;
	int f;

	f = 0;
	ways_temp = ways;
	while (ways_temp)
	{
		w_temp = ways_temp->way;
		if (ways_temp->shortest == 1 && ways_temp->donotuse != 1)
		{
			f = 1;
			while (w_temp->next)
			{
				ft_putstr(w_temp->connection);
				w_temp = w_temp->next;
			}
			ft_putstr(w_temp->connection);
		}
		ways_temp = ways_temp->next;
	}
	return (f);
}

void find_end_reset_shortest(t_links **ways)
{
	int length;
	t_links *ways_temp;

	ways_temp = *ways;
	while (ways_temp->shortest != 1)
		ways_temp = ways_temp->next;
	length = ways_temp->len;
	ways_temp = *ways;

	while (ways_temp)
	{
		if (ways_temp->len < length && ways_temp->donotuse != 1)
			length = ways_temp->len;
		ways_temp = ways_temp->next;
	}
	ways_temp = *ways;
	while (ways_temp)
	{
		if (ways_temp->donotuse != 1)
		{
			if (ways_temp->len == length)
				ways_temp->shortest = 1;
			else
				ways_temp->shortest = 0;
		}
		ways_temp = ways_temp->next;
	}
}

void find_end_set_shortest(t_links **ways)
{
	int length;
	t_links *ways_temp;

	ways_temp = *ways;
	length = ways_temp->len;
	while (ways_temp)
	{
		if (ways_temp->len < length && ways_temp->donotuse != 1)
			length = ways_temp->len;
		ways_temp = ways_temp->next;
	}
	ways_temp = *ways;
	while (ways_temp)
	{
		if (ways_temp->donotuse != 1)
		{
			if (ways_temp->len == length)
				ways_temp->shortest = 1;
			else
				ways_temp->shortest = 0;
		}
		ways_temp = ways_temp->next;
	}
}

void ft_del_list_room(t_room **head)
{
	t_room *crawler;
	t_room *prev;
	t_links *ways_cr;
	t_links *way_cr;

	crawler = *head;
	while (crawler)
	{
		prev = crawler;
//		ways_cr = crawler->links;
//		while (ways_cr)
//		{
//			way_cr = ways_cr->way;
//			while (way_cr)
//			{
//				ft_del_list(&way_cr->way);
//				way_cr = way_cr->next;
//			}
//			ft_del_list(&ways_cr->way);
//			ways_cr = ways_cr->next;
//		}
		crawler = crawler->next;
		ft_bzero(prev, sizeof(prev));
		ft_del_list(&prev->links);
		free(prev->name);
		free(prev);
	}
	*head = NULL;
	return;
}

void ft_del_list(t_links **head)
{
	t_links *crawler;
	t_links *prev;

	crawler = *head;
	while (crawler)
	{
		prev = crawler;
		crawler = crawler->next;
		ft_bzero(prev, sizeof(prev));
		free(prev);
	}
	*head = NULL;
	return;
}

int main()
{
	t_ants *all;

	all = malloc(sizeof(t_ants));
	if (reading(&all) == 0)
	{
		write_error();
		return (0);
	}
//	if (!out_ways(all->ways))
//	{
//		write_error();
//		return (0);
//	}
	find_end_set_shortest(&all->ways);
	move_ants(&all);
	t_links *w_temp;

	w_temp = (all)->ways;
	while (w_temp->next)
	{
		ft_del_list(&w_temp->way);
		w_temp = w_temp->next;
	}
	//ft_del_list_room(&(all)->rooms_info);
	t_links *fr;

	fr = (all)->ways;
//	while (fr)
//	{

//		ft_del_list(&fr->way);
//		fr = fr->next;
//	}
	//ft_del_list(&(all)->ways);
//	while (1);
	return (0);
}