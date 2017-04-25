/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:14:12 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/13 14:49:56 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i])
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	if (res != NULL)
	{
		i = 0;
		while (str[i])
		{
			res[i] = str[i];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
