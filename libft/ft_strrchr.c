/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:14:15 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/01 20:26:14 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	if (ft_strchr(s, c))
	{
		i = ft_strlen((char *)s);
		while (s[i] != c)
			i--;
		return ((char *)s + i);
	}
	else
		return (0);
}
