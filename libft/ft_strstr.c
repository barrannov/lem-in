/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrupski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:00:04 by akrupski          #+#    #+#             */
/*   Updated: 2016/11/24 16:00:05 by akrupski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *lit)
{
	int		q;
	int		r;
	char	*str;

	str = (char *)big;
	if (!(*lit))
		return (str);
	while (*str != '\0')
	{
		if (*str == *lit)
		{
			r = 0;
			q = 0;
			while (lit[q])
			{
				if (str[r++] != lit[q++])
					return (ft_strstr(++str, lit));
			}
			return (str);
		}
		str++;
	}
	return (NULL);
}
