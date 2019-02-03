/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:06:12 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/30 17:58:17 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char			*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	char			*out;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return ("");
	start = 0;
	while (is_space(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && is_space(s[end]))
		end--;
	if (!(out = (char*)malloc(end - start + 2)))
		return (NULL);
	out[end - start + 1] = '\0';
	return (ft_memcpy(out, s + start, end - start + 1));
}
