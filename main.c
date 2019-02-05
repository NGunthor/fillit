/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:24:37 by ngunthor          #+#    #+#             */
/*   Updated: 2019/02/05 14:24:55 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av)
{
	int fd;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (!(begin_check(fd)))
		ft_putstr("error\n");
	else
		ft_putstr("ok\n");
	close(fd);
	return (0);
}
