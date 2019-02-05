/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:24:44 by ngunthor          #+#    #+#             */
/*   Updated: 2019/02/05 18:24:16 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

int 				check_blocks(char *str, int ret);
int					begin_check(int fd);

void				push(t_queue **head, t_queue *new);

typedef struct		s_queue
{
	int				x[4];
	int				y[4];
	char			id;
	int				width;
	int				heigth;
	struct s_stack	*next;
}					t_queue;

#endif
