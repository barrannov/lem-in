#include "../lem-in.h"

/*int					amount_list_el(t_ants *list)
{
	t_ants	*n;
	int		i;

	i = 0;
	if (list != NULL)
	{
		n = list;
		while (n->next != NULL)
		{
			i++;
			n = n->next;
		}
	}
	i++;
	return (i);
}*/

void lst_add(t_room **stk, char *name, int position)
{
	t_room *new;
	t_room *tmp;

	new = (t_room *) malloc(sizeof(t_room));
	new->name = ft_strdup(name);
	new->position = position;
	new->next = NULL;
	if (*stk == NULL)
		(*stk) = new;
	else
	{
		tmp = *stk;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void write_error()
{
	ft_putstr("ERROR");
}