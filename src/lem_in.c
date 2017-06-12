/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:35:36 by abaranov          #+#    #+#             */
/*   Updated: 2017/05/15 13:58:02 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					out_ways(t_links *ways)
{
	t_links		*ways_temp;
	t_links		*w_temp;
	int			f;

	f = 0;
	ways_temp = ways;
	while (ways_temp)
	{
		w_temp = ways_temp->way;
		if (ways_temp->shortest == 1 && ways_temp->donotuse != 1)
		{
			f = 1;
			while (w_temp->next)
				w_temp = w_temp->next;
		}
		ways_temp = ways_temp->next;
	}
	return (f);
}

void				find_end_reset_shortest(t_links **ways)
{
	int			length;
	t_links		*ways_temp;

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
			ways_temp->shortest = (ways_temp->len == length) ? 1 : 0;
		ways_temp = ways_temp->next;
	}
}

void				find_end_set_shortest(t_links **ways)
{
	int			length;
	t_links		*ways_temp;

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
			ways_temp->shortest = (ways_temp->len == length) ? 1 : 0;
		ways_temp = ways_temp->next;
	}
}

int					main(void)
{
	t_ants		*all;

	all = malloc(sizeof(t_ants));
	all->ways = NULL;
	all->res = NULL;
	if (reading(&all) == 0)
	{
		write_error();
		return (0);
	}
	if (all->ways != NULL)
		find_end_set_shortest(&all->ways);
	if (!out_ways(all->ways))
	{
		write_error();
		return (0);
	}
	out_res(all->res);
	ft_putstr("\n");
	move_ants(&all);
	return (0);
}
