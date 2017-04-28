#include "lem-in.h"

int main()
{
	t_ants *all;

	all = malloc(sizeof(t_ants));
	if (reading(&all) == 0)
	{
		write_error();
		return (0);
	}
	return (1);
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
