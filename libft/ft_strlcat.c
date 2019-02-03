/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:01:10 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/28 14:05:17 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*odst;
	const char	*osrc;
	size_t		n;
	size_t		dsize;

	odst = dst;
	osrc = src;
	n = size;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dsize = dst - odst;
	n = size - dsize;
	if (n-- == 0)
		return (dsize + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dsize + (src - osrc));
}
