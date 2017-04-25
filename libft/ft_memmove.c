/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:38:12 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/12 13:46:41 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *s1;
	char *s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (src > dst)
	{
		while (len--)
			*s1++ = *s2++;
	}
	else
	{
		while (len--)
			s1[len] = s2[len];
	}
	return (dst);
}
