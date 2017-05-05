#include "lem-in.h"



//int main()
//{
//	char *ar;
//
//
//	ar = (char *)malloc((sizeof(char) * 5) + 1);
//
//	int i;
//
//	i = 0;
//
//	printf("%d", length((void *)&ar));
//}


void out_ways(t_links *ways)
{
	t_links *ways_temp;
	t_links *w_temp;

	ways_temp = ways;
	while (ways_temp)
	{
		w_temp = ways_temp->way;
		while (w_temp->next)
		{
			ft_putstr(" ");
			ft_putstr(w_temp->connection);
			w_temp=w_temp->next;
		}
		ft_putstr(" ");
		ft_putstr(w_temp->connection);
		ft_putstr("\n");
		ways_temp=ways_temp->next;
	}
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
	out_ways(all->ways);
	return (0);
}
/*

int say_hello()
{
	ft_putstr("hello");
	return (1);
}
int main()
{
	char *ab;

	ab = ft_strdup("qwq");
	if(!ft_strcmp("qlwq", ab) && say_hello())
	{
		ft_putstr("asa");
	}

	return (0);
}*/
