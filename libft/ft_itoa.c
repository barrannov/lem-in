/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:39:49 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/13 22:17:15 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		min(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char			*ft_itoa(int n)
{
	char			*res;
	int				len;
	unsigned int	num;

	len = 0;
	len = ft_amount_d(n);
	num = min(n);
	if (!(res = (char *)malloc(sizeof(*res) * (len + 1))))
		return (0);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len--] = num % 10 + 48;
		num = num / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
