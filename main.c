/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:24:37 by ngunthor          #+#    #+#             */
/*   Updated: 2019/03/09 19:23:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int solve(t_params params, t_tetr *tetras)
{
	char **map;

	params.map_size = 2;
	map = init_map(params.map_size);
	while (1)
	{
		place_tetr(tetras, 0, map, params);
		if (is_blank(map, params.map_size))
		{
			delete_map(map, params.map_size);
			params.map_size++;
			map = init_map(params.map_size);
		}
		else
			break ;
	}
	print_map(map, params.map_size);

}

int main(int ac, char **av)
{
	int			fd;
	t_tetr		tetrs[26];
	t_params	params;

	if (ac != 2)
	/*{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}*/
	fd = open("C:\\Users\\clfdf\\Desktop\\C\\fillit\\examples\\ok_09_block", O_RDONLY);
	if ((params.tetr_num = begin_check(fd, tetrs)) == 0)
		ft_putstr("error\n");
	else
		solve(params, tetrs);
	close(fd);
	return (0);
}
