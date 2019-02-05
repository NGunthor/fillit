/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:24:24 by ngunthor          #+#    #+#             */
/*   Updated: 2019/02/05 18:24:16 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_stack	pop(t_stack *head)
{
	t_queue		*temp;

	if (!head)
		return (NULL);
	tmp = head;
	head = nead->next;
	free (tmp);
	return (head);
}

void	push(t_stack **head, t_stack *new)
{
	t_queue *now_pos;

	if (!new || !begin_list)
		return ;
	if (*begin_list == NULL)
		*begin_list = new;
	else
	{
		now_pos = *begin_list;
		while (now_pos->next)
			now_pos = now_pos->next;
		now_pos->next = elem;
	}
}

t_list	*queue_new(void const *content, size_t content_size)
{
	t_queue *out;

	out = (t_queue*)malloc(sizeof(t_list));
	if (out == NULL)
		return (NULL);
	if (content == NULL)
	{
		out->content = NULL;
		out->content_size = 0;
	}
	else
	{
		out->content = (unsigned char*)malloc(content_size);
		if (out->content == NULL)
		{
			free(out);
			return (NULL);
		}
		out->content_size = content_size;
		ft_memmove(out->content, content, content_size);
	}
	out->next = NULL;
	return (out);
}
