/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 16:17:28 by ngunthor          #+#    #+#             */
/*   Updated: 2019/03/10 16:20:31 by ngunthor         ###   ########.fr       */
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

typedef struct		s_params
{
	int				map_size;
	int				tetr_num;
}					t_params;

int					check_blocks(char *str, int ret);
int					begin_check(int fd, t_tetr *tetr);
int					make_list(t_tetr *el, char *str, int num);
int					check_connections(char *str);
void				height_and_width(t_tetr *tetr);
char				**create_map(int tetr_num);
int					is_blank(char **map, int map_size);
char				**init_map(int map_size);
void				delete_map(char **map, int map_size);
void				rev_map(t_tetr *tetr, char **map, int map_size);
int					place_tetr(t_tetr *tetrs, int i, char **map, t_params prms);
int					is_possible(t_tetr *tetr, char **map, int x, int y);
void				print_map(char **map, int map_size);

#endif
