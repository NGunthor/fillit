/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:24:24 by ngunthor          #+#    #+#             */
/*   Updated: 2019/02/06 17:39:08 by ngunthor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_queue	*pop(t_queue *head)
{
	t_queue		*temp;

	if (!head)
		return (NULL);
	temp = head;
	head = head->next;
	free (temp);
	return (head);
}

void	push(t_queue **head, t_queue *new)
{
	t_queue *now_pos;

	if (!new || !head)
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		now_pos = *head;
		while (now_pos->next)
			now_pos = now_pos->next;
		now_pos->next = new;
	}
}

void	clear_queue(t_queue **head)
{
	t_queue	*now_pos;
	t_queue *temp;

	now_pos = *head;
	while (now_pos)
	{
		temp = now_pos;
		now_pos = now_pos->next;
		free (temp);
	}
	head = NULL;
}

t_queue		*queue_new()
{
	t_queue *out;
	int 	i;

	out = (t_queue*)malloc(sizeof(t_queue));
	if (out == NULL)
		return (NULL);
	else
	{
		while (i < 4)
		{
			out->x[i] = 0;
			out->y[i] = 0;
			i++;
		}
		out->id = 0;
		out->width = 0;
		out->heigth = 0;
	}
	out->next = NULL;
	return (out);
}
