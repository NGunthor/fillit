/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngunthor <ngunthor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:35:13 by ngunthor          #+#    #+#             */
/*   Updated: 2019/02/03 12:20:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fdlist	*select_head(t_fdlist **head, int fd)
{
	t_fdlist	*temp;

	temp = *head;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_fdlist*)malloc(sizeof(t_fdlist))))
		return (NULL);
	temp->fd = fd;
	temp->ret = 0;
	temp->data = ft_strnew(0);
	temp->next = *head;
	*head = temp;
	return (temp);
}

static void		joinstr(char **s1, char *s2)
{
	char *temp;

	temp = ft_strnew(ft_strlen(*s1) + ft_strlen(s2));
	ft_strcpy(temp, *s1);
	ft_strcat(temp, s2);
	ft_strdel(s1);
	*s1 = ft_strdup(temp);
	ft_strdel(&temp);
}

static void		move_to_out(char **data, char **line)
{
	char	*temp;
	int		n;
	int		i;

	i = 0;
	n = 0;
	temp = ft_strdup(*data);
	while (temp[i] != '\n' && temp[i])
	{
		i++;
		n++;
	}
	*line = ft_strnew(n);
	ft_strncpy(*line, *data, n);
	ft_strdel(data);
	if (n < (int)ft_strlen(temp))
		*data = ft_strdup(temp + n + 1);
	else
		*data = ft_strdup("\0");
	ft_strdel(&temp);
}

int				get_next_line(const int fd, char **line)
{
	static t_fdlist	*head;
	t_fdlist		*current;
	char			buff[BUFF_SIZE + 1];

	if (read(fd, buff, 0) < 0 || fd < 0 || line == 0)
		return (-1);
	current = select_head(&head, fd);
	while ((current->ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[current->ret] = '\0';
		joinstr(&current->data, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ft_strlen(current->data) == 0)
		return (0);
	move_to_out(&current->data, line);
	return (1);
}
