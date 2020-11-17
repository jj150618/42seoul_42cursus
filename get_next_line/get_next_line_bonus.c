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

t_list	*find_buff(t_list *lst_buff, int fd)
{
	while (lst_buff)
	{
		if (lst_buff->fd == fd)
			break ;
		if (lst_buff->next == NULL)
			if (!(lst_buff->next = new_buff(fd)))
				return (0);
		lst_buff = lst_buff->next;
	}
	return (lst_buff);
}

t_list	*new_buff(int fd)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (0);
	if (!(new->buff = malloc(1)))
		return (0);
	new->buff[0] = '\0';
	new->fd = fd;
	new->next = NULL;
	return (new);
}

int		find_new_line(char **line, t_list *lst_buf)
{
	size_t	i;
	size_t	j;
	int		found;

	found = 0;
	i = 0;
	j = 0;
	while (lst_buf->buff[i] != '\0')
		if (lst_buf->buff[i++] == '\n')
		{
			found = 1;
			*line = malloc(i);
			ft_strlcpy(*line, lst_buf->buff, i);
			break ;
		}
	if (found)
		ft_strlcpy(lst_buf->buff, lst_buf->buff + i,
					ft_strlen(lst_buf->buff) + 1);
	return (found);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*lst_buf;
	ssize_t			size;
	int				found;

	if (BUFFER_SIZE <= 0 || !line || (!head && !(head = new_buff(fd))) ||
		!(lst_buf = find_buff(head, fd)))
		return (-1);
	*line = 0;
	while (!(found = find_new_line(line, lst_buf)) &&
		((size = read(fd, lst_buf->temp_buff, BUFFER_SIZE)) > 0))
	{
		lst_buf->temp_buff[size] = '\0';
		lst_buf->buff = ft_strjoin(&(lst_buf->buff), lst_buf->temp_buff);
	}
	if (found)
		return (found);
	if (size < 0)
		return (-1);
	*line = malloc(ft_strlen(lst_buf->buff) + 1);
	ft_strlcpy(*line, lst_buf->buff, ft_strlen(lst_buf->buff) + 1);
	free_buff(&head, fd);
	return (0);
}