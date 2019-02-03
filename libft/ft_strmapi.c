/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:02:34 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/29 17:03:39 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*outstr;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if ((outstr = (char*)malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		outstr[i] = f(i, s[i]);
		i++;
	}
	outstr[i] = '\0';
	return (outstr);
}
