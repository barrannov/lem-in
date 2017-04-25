/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:48:47 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/12 18:05:51 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && (n != 0))
	{
		if (*s1 != *s2)
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		n--;
		s1++;
		s2++;
	}
	return (0);
}
