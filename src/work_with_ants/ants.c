#include "../lem-in.h"

int add_new_ant(int number, int amount, t_links **ways)
{
	t_links *ways_temp;
	t_links *w_temp;

	ways_temp = *ways;
	while (ways_temp && number <= amount)
	{
		if (ways_temp->shortest == 1 && ways_temp->donotuse != 1)
		{
			ft_putstr("L");
			ft_putnbr(number);
			ft_putstr("-");
			ft_putstr(ways_temp->way->next->connection);
			ft_putstr(" ");
			ways_temp->way->next->number_of_ant = number;
			ways_temp->way->next->busy = 1;
			number++;
		}
		ways_temp = ways_temp->next;
	}
	return (number);
}

void move_current(int number, t_links **ways)
{
	t_links *ways_temp;
	t_links *w_temp;

	ways_temp = *ways;
	while (ways_temp->next)
	{
		w_temp = ways_temp->way;
		if (ways_temp->shortest == 1)
		{
			while (w_temp->next)
			{
				if (w_temp->number_of_ant == number)
				{
					ft_putstr("L");
					ft_putnbr(w_temp->number_of_ant);
					ft_putstr("-");
					ft_putstr(w_temp->next->connection);
					ft_putstr(" ");
					w_temp->next->number_of_ant = w_temp->number_of_ant;
					w_temp->busy = 0;
					return;

				}
				w_temp = w_temp->next;
			}
		}
		ways_temp = ways_temp->next;
	}
}

void move_ants(t_ants **all)
{
	int on_way; //количество муравъев уже в пути
	int i;
	int test;

	test = 20;
	on_way = 1;
	while (test--)
	{
		if (on_way <= (*all)->amount_ants)
		{
			on_way = add_new_ant(on_way, (*all)->amount_ants, &(*all)->ways);
		}
		i = 1;
		ft_putstr("\n");
		while (i < on_way)
		{
			move_current(i, &(*all)->ways);
			i++;
		}
	}
}