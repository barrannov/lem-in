#include "lem-in.h"

int validation(t_ants *all)
{
	int y;
	int x;
	char *line;
	int i;

	i = 0;
	get_next_line(0, &line);
	if(is_number(line))
		all->amount_ants = ft_atoi(line);
	else
		return (0);

	while (y-- > 0)
	{
		get_next_line(0, &line);
		//all->map[i] = line + 4;
		//	ft_putstr_fd(all->map[i], fd);
		//	ft_putstr_fd("\n", fd);
		i++;
	}
	//all->map[i] = NULL;
	return (1);
}