/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:50:09 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/13 19:50:42 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*full(char *s, int c)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(ft_count_l((char *)s, c) * sizeof(char) + 1);
	while (i < ft_count_l((char *)s, c))
	{
		res[i] = (char)s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
