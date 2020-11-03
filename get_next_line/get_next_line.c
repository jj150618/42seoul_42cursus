/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:45:58 by junghkim          #+#    #+#             */
/*   Updated: 2020/11/03 12:31:04 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	handle_line(char **line, char **note, char *check_nl)
{
	char	*temp;

	if (nl_here != NULL)
	{
		*line = ft_strndup(*note, check_nl - *note);
		tmp = ft_strndup(check_nl + 1, ft_strlen(check_nl + 1));
		free(*note);
		*note = temp;
		return (NL);
	}
	if (*note != NULL)
	{
		*line = *note;
		*note = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (_EOF);
}

int			get_next_line(int fd, char **line)
{
	static char	*note[OPEN_MAX];
	static char	buff[BUFFER_SIZE + 1];
	int			byte;
	char		*temp;
	char		*check_nl;

	if (fd < 0 || line == NULL || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	while ((check_nl = ft_strchr(note[fd], '\n')) == 0
			&& (byte = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[byte] = 0;
		if (note[fd] == NULL)
			temp = ft_strndup(buff, byte);
		else
			temp = ft_strjoin(note[fd], buff);
		if (note[fd] != 0)
			free(note[fd]);
		note[fd] = tmp;
	}
	if (byte < 0)
		return (-1);
	return (handle_line(line, &note[fd], check_nl));
}
