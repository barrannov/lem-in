/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:00:51 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/13 14:48:14 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	char	*test;
	int		i;

	if (s)
	{
		i = ft_strlen((char *)s);
		while ((*s == ' ' || *s == '\t' || *s == '\n') && i--)
			s++;
		if (i)
		{
			test = ((char *)s + (i - 1));
			while ((*test == ' ' || *test == '\t' || *test == '\n') && i--)
				test--;
		}
		if ((new = (char*)malloc(i + 1)))
		{
			new = ft_strncpy(new, s, i);
			*(new + i) = '\0';
			return (new);
		}
	}
	return (NULL);
}
