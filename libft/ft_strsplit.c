/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:25:10 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/29 19:15:23 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*word_cpy(const char *str, char c)
{
	int		i;
	char	*out;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(out = (char*)malloc(i)))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

static int	word_count(const char *str, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count + 1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**outarr;
	int		i;
	int		oi;

	i = 0;
	oi = 0;
	if (s == 0 || !(outarr = (char**)malloc(sizeof(char*) * word_count(s, c))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(outarr[oi] = word_cpy(s + i, c)))
				return (ft_arrfree(outarr, oi));
			while (s[i] && s[i] != c)
				i++;
			oi++;
		}
		else
			i++;
	}
	outarr[oi] = 0;
	return (outarr);
}
