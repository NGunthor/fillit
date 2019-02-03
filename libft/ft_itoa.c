/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:20:26 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/30 18:15:59 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n)
{
	int length;

	length = 0;
	if (n <= 0)
		length++;
	ft_abs(n);
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char		*ft_itoa(int n)
{
	char	*out;
	int		length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = nbrlen(n);
	out = ft_strnew(length);
	if (out == NULL)
		return (NULL);
	out[0] = '0';
	if (n < 0)
		out[0] = '-';
	n = ft_abs(n);
	while (n > 0)
	{
		out[--length] = n % 10 + '0';
		n = n / 10;
	}
	return (out);
}
