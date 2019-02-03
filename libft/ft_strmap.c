/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:58:45 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/29 17:00:32 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*outstr;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((outstr = (char*)malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		outstr[i] = f(s[i]);
		i++;
	}
	outstr[i] = '\0';
	return (outstr);
}
