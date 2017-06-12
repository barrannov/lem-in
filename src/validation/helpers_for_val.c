/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_for_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:38:19 by abaranov          #+#    #+#             */
/*   Updated: 2017/05/13 18:38:20 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int					check_spaces(char *line)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			s++;
		i++;
	}
	return (s);
}

int					chack_start_end(t_room *rooms)
{
	t_room	*temp;
	int		st;
	int		end;

	st = 0;
	end = 0;
	temp = rooms;
	while (temp)
	{
		if (temp->position == START)
			st = START;
		if (temp->position == END)
			end = END;
		temp = temp->next;
	}
	if (st == START && end == END)
		return (1);
	else
		return (0);
}
