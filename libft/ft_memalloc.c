/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:10:58 by ngunthor          #+#    #+#             */
/*   Updated: 2018/11/28 14:01:18 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	unsigned int	i;

	if ((ptr = (unsigned char*)malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
