/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:00:47 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/12 14:36:08 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst1, const char *src, size_t len)
{
	size_t		i;
	char		*dst;

	dst = dst1;
	i = 0;
	while (*src && i < len)
	{
		*dst++ = *src++;
		i++;
	}
	while (i < len)
	{
		*dst++ = '\0';
		i++;
	}
	return (dst1);
}
