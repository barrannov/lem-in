/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:38:35 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/12 18:23:52 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t c;

	i = ft_strlen(s1);
	c = 0;
	while (n && s2[c])
	{
		s1[i] = s2[c];
		c++;
		i++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
