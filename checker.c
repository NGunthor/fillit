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

int		make_list(t_queue *head, char *str, int num)
{
	t_queue 	*el;
	int 		i;
	int			index;
	int			x_offset;
	int			y_offset;

	i = -1;
	index = 0;
	el = queue_new();
	while (str[++i])
	{
		if (str[i] == '#')
		{
			el->x[index] = i % 5;
			el->y[index] = i / 5;
			//el->id != '\0' ? x_offset = el->x[0] : 0;
			//el->id != '\0' ? y_offset = el->y[0] : 0;
			//el->x[index] -= x_offset;
			//el->y[index] -= y_offset;
			el->id = 'A' + num;
			index++;
		}
	}
	push(&head, el);
	return (1);
}

t_queue		*begin_check(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int 	temp;
	int 	i;
	t_queue *head;

	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (!ret && temp != 20)
			return (0);
		buff[ret] = '\0';
		if(!check_blocks(buff, ret) || !check_connections(buff))
			return (0);
		temp = ret;
		make_list(head, buff, i);
		i++;
	}
	return (head);
}
