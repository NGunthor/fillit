/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:54:51 by ngunthor          #+#    #+#             */
/*   Updated: 2019/03/13 14:22:41 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_placeble(t_tetr *tetr, char **map, int x, int y)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if (map[y + tetr->y[index]][x + tetr->x[index]] != '.')
			return (0);
		index++;
	}
	return (1);
}

void			rev_map(t_tetr *tetr, char **map, int map_size)
{
	int x;
	int y;
	int index;

	y = 0;
	index = 0;
	while (y < map_size)
	{
		x = 0;
		while (x < map_size)
		{
			if (map[y][x] == tetr->id)
			{
				while (index < 4)
				{
					map[y + tetr->y[index]][x + tetr->x[index]] = '.';
					index++;
				}
				return ;
			}
			x++;
		}
		y++;
	}
}

int				is_possible(t_tetr *tetr, char **map, int x, int y)
{
	int index;

	index = 0;
	if (is_placeble(tetr, map, x, y))
	{
		while (index < 4)
		{
			map[y + tetr->y[index]][x + tetr->x[index]] = tetr->id;
			index++;
		}
		return (1);
	}
	return (0);
}

int				place_tetr(t_tetr *tetrs, int i, char **map, t_params prms)
{
	int done;
	int x;
	int y;

	done = 0;
	y = -1;
	while (++y < prms.map_size - tetrs[i].height)
	{
		x = -1;
		while (++x < prms.map_size - tetrs[i].width)
		{
			if (i < prms.tetr_num)
			{
				if (is_possible(&tetrs[i], map, x, y))
					done = place_tetr(tetrs, i + 1, map, prms);
				if (done)
					return (1);
			}
		}
	}
	if (i < prms.tetr_num)
		rev_map(&tetrs[i - 1], map, prms.map_size);
	else
		return (1);
	return (0);
}
