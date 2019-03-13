/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 16:08:25 by ngunthor          #+#    #+#             */
/*   Updated: 2019/03/13 14:09:20 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int map_size)
{
	char	**map;
	int		i;

	if (!(map = (char **)malloc(sizeof(char *) * (map_size + 1))))
		return (NULL);
	i = 0;
	while (i < map_size)
	{
		if (!(map[i] = ft_strnew(map_size)))
			return (NULL);
		i++;
	}
	map[map_size] = "\0";
	return (map);
}

char	**init_map(int map_size)
{
	char	**map;
	int		i;
	int		j;

	map = create_map(map_size);
	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		is_blank(char **map, int map_size)
{
	int x;
	int y;

	y = 0;
	while (y < map_size)
	{
		x = 0;
		while (x < map_size)
		{
			if (map[x][y] != '.')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	delete_map(char **map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_map(char **map, int map_size)
{
	int i;
	int j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
