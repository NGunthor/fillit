/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:48:13 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/28 14:36:37 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int hi;
	int ni;

	hi = 0;
	while (haystack[hi])
	{
		ni = 0;
		while (haystack[hi + ni] == needle[ni] && haystack[hi + ni])
			ni++;
		if (needle[ni] == '\0')
			return ((char*)haystack + hi);
		hi++;
	}
	if (!haystack[0] && !needle[0])
		return ((char*)haystack);
	return (NULL);
}
