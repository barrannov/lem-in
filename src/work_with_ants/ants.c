/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:26:39 by abaranov          #+#    #+#             */
/*   Updated: 2017/05/15 13:20:49 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int					add_new_ant(int number, int amount, t_links **ways)
{
	t_links *ways_temp;

	ways_temp = *ways;
	while (ways_temp && number <= amount)
	{
		if (ways_temp->shortest == 1 && ways_temp->donotuse != 1)
		{
			ft_putstr(BLUE"L");
			ft_putnbr(number);
			ft_putstr("-");
			ft_putstr(ways_temp->way->next->c_name);
			ft_putstr(" "RESET);
			ways_temp->way->next->number_of_ant = number;
			number++;
			ways_temp->len++;
			find_end_reset_shortest(ways);
		}
		ways_temp = ways_temp->next;
	}
	return (number);
}

void				print_ants(t_links *w_temp)
{
	if (w_temp->next->next)
	{
		ft_putstr("L");
		ft_putnbr(w_temp->number_of_ant);
		ft_putstr("-");
		ft_putstr(w_temp->next->c_name);
		ft_putstr(" ");
	}
	else
	{
		ft_putstr(GREEN"L");
		ft_putnbr(w_temp->number_of_ant);
		ft_putstr("-");
		ft_putstr(w_temp->next->c_name);
		ft_putstr(" "RESET);
	}
}

int					move_current(int number, t_links **ways, t_links *w_temp)
{
	t_links *ways_temp;

	ways_temp = *ways;
	while (ways_temp)
	{
		w_temp = ways_temp->way;
		if (ways_temp->donotuse != 1)
			while (w_temp->next)
			{
				if (w_temp->number_of_ant == number)
				{
					print_ants(w_temp);
					w_temp->next->number_of_ant = w_temp->number_of_ant;
					w_temp->number_of_ant = 0;
					return (1);
				}
				w_temp = w_temp->next;
			}
		ways_temp = ways_temp->next;
	}
	return (0);
}

void				move_ants(t_ants **all)
{
	int			on_way;
	int			i;
	int			temp;
	t_links		*w_temp;

	w_temp = NULL;
	on_way = 1;
	while (1)
	{
		if (on_way <= (*all)->amount_ants)
			on_way = add_new_ant(on_way, (*all)->amount_ants, &(*all)->ways);
		i = 1;
		ft_putstr("\n");
		temp = 0;
		while (i < on_way)
		{
			temp = move_current(i, &(*all)->ways, w_temp);
			i++;
		}
		if (i - 1 == (*all)->amount_ants && temp == 0)
			return ;
	}
}
