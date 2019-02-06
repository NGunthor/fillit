/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:24:37 by ngunthor          #+#    #+#             */
/*   Updated: 2019/02/06 17:39:36 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av)
{
	int		fd;
	t_queue	*list;
	t_queue *temp;

	list = NULL;
	/*if (ac != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}*/
	fd = open("/Users/ngunthor/my_git/fillit/examples/ok_02", O_RDONLY);
	if (!(list = begin_check(fd)))
		ft_putstr("error\n");
	else
		ft_putstr("ok\n");
	temp = list;
	printf("%p\n", list);
	while (temp)
	{
		printf("%c\n", temp->id);
		temp = temp->next;
	}
	clear_queue(&list);
	close(fd);
	return (0);
}
