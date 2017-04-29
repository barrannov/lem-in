#include "../lem-in.h"

int					amount_list_el(t_room *list)
{
	t_room	*n;
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
}

void lst_add(t_room **stk, char *name, int position)
{
	t_room *new;
	t_room *tmp;

	new = (t_room *) malloc(sizeof(t_room));
	new->name = ft_strdup(name);
	new->position = position;
	new->ind = ix;
	new->next = NULL;
	if (*stk == NULL)
		(*stk) = new;
	else
	{
		tmp = *stk ;
		if (amount_list_el(*stk) > 1)
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	ix++;
}

void write_error()
{
	ft_putstr("ERROR");
}