/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:53:15 by abaranov          #+#    #+#             */
/*   Updated: 2017/04/07 17:24:28 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "libft.h"
# define BUFF_SIZE 1

typedef struct		s_struct
{
	int				fd;
	char			*balance;
	struct s_struct	*next;
}					t_struct;

int					get_next_line(const int fd, char **line);

#endif
