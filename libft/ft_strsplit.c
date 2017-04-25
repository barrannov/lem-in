/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:38:01 by abaranov          #+#    #+#             */
/*   Updated: 2016/12/14 13:16:19 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_ll(char *s, char c)
{
	int test;
	int i;

	test = 0;
	i = 0;
	while (((char)s[i]) != c && ((char)s[i]) != '\0')
		i++;
	return (i);
}

static	char	*fulll(char *s, int c)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(ft_count_ll((char *)s, c) * sizeof(char) + 1);
	while (i < ft_count_ll((char *)s, c))
	{
		res[i] = (char)s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int		ft_countt_w(char const *s, char c)
{
	char	*p;
	int		cw;

	if (!s)
		return (0);
	cw = 0;
	while (*s)
	{
		(*s == c && *s) ? s++ : 0;
		p = (char *)s;
		while (*p != c && *p)
			p++;
		(*s != c && *s) ? cw++ : 0;
		s = p;
	}
	return (cw);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		lol[3];

	if (!(r = (char **)malloc((ft_countt_w(s, c) + 1) * 8)))
		return (NULL);
	lol[1] = ft_count_w((char *)s, c);
	lol[0] = 1;
	lol[2] = 0;
	while (lol[2] < lol[1] && s)
	{
		if (*(char *)s == c)
		{
			while (*((char *)s) != c && s++)
				;
			lol[0] = 1;
		}
		else if (lol[0] == 1 && s)
		{
			r[lol[2]++] = fulll((char *)s, c);
			lol[0] = 0;
		}
		s++;
	}
	r[lol[2]++] = (char *)'\0';
	return (r);
}
