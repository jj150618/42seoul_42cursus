/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:45:58 by junghkim          #+#    #+#             */
/*   Updated: 2020/11/25 12:05:13 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_list(t_list **head, int fd)
{
	t_list	*temp;
	t_list	*free_list;

	temp = *head;
	if (temp->fd == fd)
	{
		*head = temp->next;
		free(temp->buff);
		free(temp);
		return ;
	}
	while (temp->next->fd != fd)
		temp = temp->next;
	free_list = temp->next;
	temp->next = free_list->next;
	free(free_list->buff);
	free(free_list);
}

t_list	*new_list(int fd)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (0);
	if (!(new->buff = malloc(sizeof(char) * 1)))
		return (0);
	new->buff[0] = '\0';
	new->fd = fd;
	new->next = NULL;
	return (new);
}

t_list	*find_list(t_list *list_buff, int fd)
{
	while (list_buff)
	{
		if (list_buff->fd == fd)
			break ;
		if (list_buff->next == NULL)
			if (!(list_buff->next = new_list(fd)))
				return (0);
		list_buff = list_buff->next;
	}
	return (list_buff);
}

int		find_nl(char **line, t_list *list_buff)
{
	size_t	i;
	size_t	j;
	int		check;

	check = 0;
	i = 0;
	while (list_buff->buff[i] != '\0')
		if (list_buff->buff[i++] == '\n')
		{
			check = 1;
			*line = malloc(i);
			ft_strlcpy(*line, list_buff->buff, i);
			break ;
		}
	j = ft_strlen(list_buff->buff);
	if (check)
		ft_strlcpy(list_buff->buff, list_buff->buff + i, j + 1);
	return (check);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*list_buff;
	ssize_t			size;
	int				check;

	if (BUFFER_SIZE <= 0 || !line || (!head && !(head = new_list(fd))) ||
		!(list_buff = find_list(head, fd)) || fd < 0)
		return (-1);
	*line = 0;
	while (!(check = find_nl(line, list_buff)) &&
		((size = read(fd, list_buff->temp_buff, BUFFER_SIZE)) > 0))
	{
		list_buff->temp_buff[size] = '\0';
		list_buff->buff = ft_strjoin(&(list_buff->buff), list_buff->temp_buff);
	}
	if (check)
		return (check);
	if (size < 0)
		return (-1);
	*line = malloc(ft_strlen(list_buff->buff) + 1);
	ft_strlcpy(*line, list_buff->buff, ft_strlen(list_buff->buff) + 1);
	free_list(&head, fd);
	return (0);
}
