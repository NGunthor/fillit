/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:10:16 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/29 21:59:26 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (s > d)
	{
		i = 0;
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	else
		while (len)
		{
			len--;
			*(d + len) = *(s + len);
		}
	return (dst);
}
