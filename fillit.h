/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:24:44 by ngunthor          #+#    #+#             */
/*   Updated: 2019/02/06 17:40:09 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct		s_queue
{
	int				x[4];
	int				y[4];
	char			id;
	int				width;
	int				heigth;
	struct s_queue	*next;
}					t_queue;

int 				check_blocks(char *str, int ret);
t_queue				*begin_check(int fd);
int					make_list(t_queue *head, char *str, int num);

t_queue				*queue_new();
void				push(t_queue **head, t_queue *new);
t_queue				*pop(t_queue *head);
void				clear_queue(t_queue **head);

#endif
