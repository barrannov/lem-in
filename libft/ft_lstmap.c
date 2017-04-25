/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:48:07 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/12 13:28:50 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *prev;
	t_list *new;
	t_list *beg;

	if (!lst)
		return (NULL);
	new = f(lst);
	beg = new;
	prev = new;
	while (lst->next)
	{
		lst = lst->next;
		new = f(lst);
		prev->next = new;
		prev = new;
	}
	new->next = NULL;
	return (beg);
}
