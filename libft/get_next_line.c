/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:26:33 by abaranov          #+#    #+#             */
/*   Updated: 2017/02/06 16:42:17 by abaranov         ###   ########.fr       */
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
	return (str);
}

t_struct				*change_list(int fd, t_struct **head)
{
	t_struct			*tmp;

	tmp = *head;
	if (tmp != NULL)
	{
		while ((tmp != NULL) && (tmp->fd != fd))
			tmp = tmp->next;
		if (tmp && tmp->fd == fd)
			return (tmp);
	}
	if (tmp == NULL)
	{
		tmp = malloc(sizeof(t_struct));
		tmp->fd = fd;
		tmp->balance = "\0";
		tmp->next = NULL;
	}
	*head != NULL ? tmp->next = *head : 0;
	*head = tmp;
	return (*head);
}

int						get_next_line(const int fd, char **line)
{
	char				*str;
	int					i;
	int					t;
	static t_struct		*temp;
	t_struct			*res;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1 || BUFF_SIZE < 0)
		return (-1);
	t = 0;
	i = 0;
	res = change_list(fd, &temp);
	str = (*(res->balance)) ? res->balance : ft_strnew(BUFF_SIZE);
	res->balance = ft_strnew(BUFF_SIZE);
	check_n(str) ? str = start(fd, str) : 0;
	*line = ft_strnew(ft_strlen(str));
	while (str[i] != '\n' && str[i])
		(*line)[t++] = str[i++];
	t = 0;
	str[i] == '\n' ? i++ : 0;
	while (str[i])
		res->balance[t++] = str[i++];
	free(str);
	if (i == 0)
		return (0);
	return (1);
}
