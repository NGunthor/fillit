/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:35:25 by ngunthor          #+#    #+#             */
/*   Updated: 2019/01/21 01:08:32 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include "libft/libft.h"
# include <stdlib.h>

typedef struct		s_fdlist
{
	char			*data;
	int				fd;
	int				ret;
	struct s_fdlist	*next;
}					t_fdlist;

int					get_next_line(const int fd, char **line);

#endif
