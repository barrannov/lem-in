/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:28:19 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/12 13:26:56 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *nexton;

	next = *alst;
	while (next)
	{
		nexton = next->next;
		del(next->content, next->content_size);
		free(next);
		next = nexton;
	}
	*alst = NULL;
}
