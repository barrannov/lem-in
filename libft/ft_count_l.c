/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:48:27 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/14 13:17:23 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_l(char *s, char c)
{
	int test;
	int i;

	test = 0;
	i = 0;
	while (((char)s[i]) != c && ((char)s[i]) != '\0')
		i++;
	return (i);
}