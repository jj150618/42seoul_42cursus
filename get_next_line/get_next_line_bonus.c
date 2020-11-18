#include "get_next_line_bonus.h"

void	free_buff(t_list **head, int fd)
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

t_list	*new_buff(int fd)
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

t_list	*find_buff(t_list *list_buff, int fd)
{
	while (list_buff)
	{
		if (list_buff->fd == fd)
			break ;
		if (list_buff->next == NULL)
			if (!(list_buff->next = new_buff(fd)))
				return (0);
		list_buff = list_buff->next;
	}
	return (list_buff);
}

int		find_new_line(char **line, t_list *list_buff)
{
	size_t	i;
	int		found;

	found = 0;
	i = 0;
	while (list_buff->buff[i] != '\0')
		if (list_buff->buff[i++] == '\n')
		{
			found = 1;
			*line = malloc(i);
			ft_strlcpy(*line, list_buff->buff, i);
			break ;
		}
	if (found)
		ft_strlcpy(list_buff->buff, list_buff->buff + i,
					ft_strlen(list_buff->buff) + 1);
	return (found);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*list_buff;
	ssize_t			size;
	int				found;

	if (BUFFER_SIZE <= 0 || !line || (!head && !(head = new_buff(fd))) ||
		!(list_buff = find_buff(head, fd)))
		return (-1);
	*line = 0;
	while (!(found = find_new_line(line, list_buff)) &&
		((size = read(fd, list_buff->temp_buff, BUFFER_SIZE)) > 0))
	{
		list_buff->temp_buff[size] = '\0';
		list_buff->buff = ft_strjoin(&(list_buff->buff), list_buff->temp_buff);
	}
	if (found)
		return (found);
	if (size < 0)
		return (-1);
	*line = malloc(ft_strlen(list_buff->buff) + 1);
	ft_strlcpy(*line, list_buff->buff, ft_strlen(list_buff->buff) + 1);
	free_buff(&head, fd);
	return (0);
}