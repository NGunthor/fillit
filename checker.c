/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:24:53 by ngunthor          #+#    #+#             */
/*   Updated: 2019/02/06 17:40:30 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	check_connections(char *str)
{
	int 	i;
	int 	connection;
	int		sharps;

	i = 0;
	connection = 0;
	sharps = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			connection += (i - 1 >= 0 && str[i - 1] == '#');
			connection += (i + 1 < 20 && str[i + 1] == '#');
			connection += (i - 5 >= 0 && str[i - 5] == '#');
			connection += (i + 5 < 20 && str[i + 5] == '#');
			sharps++;
		}
		i++;
	}
	return ((connection == 6 || connection == 8) && sharps == 4);
}

int 	check_blocks(char *str, int ret)
{
	int 	i;

	if (ret < 20 || ret > 21)
		return (0);
	i = 0;
	while (str[i])
	{
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
		{
			if (str[i] != '\n')
				return (0);
			i++;
			continue;
		}
		if (str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	//if (ret == 20 && i == 20)
	//	return (str[i] == '\0');
	return (1);
}



int		make_list(t_tetr *el, char *str, int num)
{
	int 		i;
	int			index;
	int			x_offset;
	int			y_offset;
	char		c;

	c = 'A' + num;
	i = -1;
	index = 0;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			el->x[index] = i % 5;
			el->y[index] = i / 5;
			x_offset = (el->id != c) ? el->x[0] : x_offset;
			y_offset = (el->id != c) ? el->y[0] : y_offset;
			el->x[index] -= x_offset;
			el->y[index] -= y_offset;
			el->id = c;
			index++;
		}
	}
	return (1);
}

void	height_and_width(t_tetr *tetr)
{
    tetr->height = 0;
    tetr->width = 0;
    tetr->height = tetr->y[3] - tetr->y[0];
    tetr->width = tetr->x[3] - tetr->x[0];
}

int		begin_check(int fd, t_tetr *tetr)
{
	char	buff[BUFF_SIZE + 1];
	t_tetr	list;
	int		ret;
	int 	temp;
	int 	i;

	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 20 && temp != 20)
			return (0);
		buff[ret] = '\0';
		if(!check_blocks(buff, ret) || !check_connections(buff))
			return (0);
		temp = ret;
		make_list(&list, buff, i);
		tetr[i] = list;
		height_and_width(&tetr[i]);
		i++;
	}
	return (i);
}
