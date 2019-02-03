/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:09:41 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/26 19:12:00 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while ((unsigned int)s1[i] &&
					(unsigned int)s1[i] == (unsigned int)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
