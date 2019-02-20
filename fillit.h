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

typedef struct		s_tetr
{
	int				x[4];
	int				y[4];
	char			id;
	int				width;
	int				height;
}					t_tetr;

typedef struct      s_params
{
    int             map_size;
    int             tetr_num;
}                   t_params;

int 				check_blocks(char *str, int ret);
int					begin_check(int fd, t_tetr *tetr);
int					make_list(t_tetr *el, char *str, int num);
char                **create_map(int tetr_num);
char                **init_map(int map_size);
void                delete_map(char **map, int map_size);
void    rev_map


#endif
