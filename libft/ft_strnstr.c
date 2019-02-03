/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:00:22 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/28 14:55:27 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t hi;
	size_t ni;

	hi = 0;
	while (haystack[hi] && hi < len)
	{
		ni = 0;
		while (haystack[hi + ni] == needle[ni] && haystack[hi + ni] &&
																hi + ni < len)
			ni++;
		if (needle[ni] == '\0')
			return ((char*)haystack + hi);
		hi++;
	}
	if ((!haystack[0] && !needle[0]))
		return ((char*)haystack);
	return (NULL);
}
