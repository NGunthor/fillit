/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:20:56 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/26 19:05:33 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destination;
	unsigned char		ch;
	size_t				i;

	source = src;
	destination = dest;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*(destination + i) = *(source + i);
		if (*(source + i) == ch)
		{
			*(destination + i) = *(source + i);
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
