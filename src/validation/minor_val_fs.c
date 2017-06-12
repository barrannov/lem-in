/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_val_fs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:39:13 by abaranov          #+#    #+#             */
/*   Updated: 2017/05/13 18:40:24 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int					amount_links(t_links *list)
{
	t_links	*n;
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

int					amount_list_el_rooms(t_room *list)
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

void				lst_add_links(t_links **stk, char *connection)
{
	t_links		*new;
	t_links		*tmp;

	new = (t_links *)malloc(sizeof(t_links));
	new->c_name = connection;
	new->way = NULL;
	new->next = NULL;
	if (*stk == NULL)
		(*stk) = new;
	else
	{
		tmp = *stk;
		if (amount_links(*stk) > 1)
			while (tmp->next)
			{
				tmp = tmp->next;
			}
		tmp->next = new;
	}
}

void				lst_add_rooms(t_room **stk, char *name, int position)
{
	t_room		*new;
	t_room		*tmp;

	new = (t_room *)malloc(sizeof(t_room));
	new->name = name;
	new->position = position;
	new->links = NULL;
	new->next = NULL;
	if (*stk == NULL)
		(*stk) = new;
	else
	{
		tmp = *stk;
		if (amount_list_el_rooms(*stk) > 1)
			while (tmp->next)
			{
				tmp = tmp->next;
			}
		tmp->next = new;
	}
}

void				write_error(void)
{
	ft_putstr("ERROR");
}
