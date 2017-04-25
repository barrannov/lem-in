/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:07:20 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/12 13:42:06 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*p;

	p = (void *)s;
	i = 0;
	while (i < (int)n)
	{
		if (p[i++] == (unsigned char)c)
			return (p + i - 1);
	}
	return (NULL);
}
