/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:50:56 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/13 19:09:44 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	int		r;
	char	*str;

	str = (char *)big;
	if (!(*lit))
		return (str);
	while (*str != '\0' && len != 0)
	{
		if (*str == *lit)
		{
			r = 0;
			while (str[r] == lit[r] && r < (int)len && lit[r] != '\0')
				r++;
			if (lit[r] == '\0')
				return (str);
		}
		str++;
		len--;
	}
	return (NULL);
}
