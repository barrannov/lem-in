/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:26:33 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/07 20:02:49 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int						check_n(char *str)
{
	int					i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (0);
	return (1);
}

char					*start(int fd, char *str)
{
	char				*temp;
	char				*freea;

	temp = ft_strnew(BUFF_SIZE);
	ft_bzero(temp, BUFF_SIZE);
	if (read(fd, temp, BUFF_SIZE) > 0)
	{
		freea = ft_strdup(str);
		free(str);
		str = ft_strjoin(freea, temp);
		free(freea);
		free(temp);
		if (check_n(str))
			return (start(fd, str));
	}
	else
		free(temp);
	return (str);
}

int						get_next_line(const int fd, char **line)
{
	char				*str;
	int					i;
	int					t;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1 || BUFF_SIZE < 0)
		return (-1);
	t = 0;
	i = 0;
	str = ft_strnew(BUFF_SIZE);
	str = start(fd, str);
	*line = ft_strnew(ft_strlen(str));
	while (str[i] != '\n' && str[i])
		(*line)[t++] = str[i++];
	str[i] == '\n' ? i++ : 0;
	free(str);
	if (i == 0)
		return (0);
	return (1);
}
