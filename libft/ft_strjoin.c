/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:58:57 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/29 18:04:50 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	if (!(out = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (*s1)
	{
		out[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		out[i] = *s2;
		i++;
		s2++;
	}
	out[i] = '\0';
	return (out);
}
