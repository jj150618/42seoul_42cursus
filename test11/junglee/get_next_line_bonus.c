/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:15:02 by junghlee          #+#    #+#             */
/*   Updated: 2020/10/20 20:10:19 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		gnl_get_line(t_buf **prv, char *endl_pos, char **line)
{
	ssize_t		rd_len;
	char		*del;

	if (!(*prv))
	{
		*line = ft_strndup("", 0);
		return (GNL_EOF);
	}
	if (!endl_pos)
	{
		*line = ft_strndup((*prv)->buf, (*prv)->len);
		return (GNL_EOF);
	}
	else
	{
		rd_len = endl_pos - (*prv)->buf + 1;
		*line = ft_strndup((*prv)->buf, rd_len - 1);
		(*prv)->len -= rd_len;
		del = (*prv)->buf;
		(*prv)->buf = ft_strndup((*prv)->buf + rd_len, (*prv)->len);
		free(del);
		return (GNL_SUCCESS);
	}
}

int		gnl_append_buf(t_buf **prv, char *tmp_buf, ssize_t tmp_len)
{
	char	*joined;

	if (!(*prv))
	{
		if (!(*prv = (t_buf *)malloc(sizeof(t_buf))))
			return (GNL_ERROR);
		if (!(joined = ft_strndup(tmp_buf, tmp_len)))
			return (GNL_ERROR);
		(*prv)->len = tmp_len;
	}
	else
	{
		if (!(joined = gnl_join((*prv)->buf, (*prv)->len, tmp_buf, tmp_len)))
			return (GNL_ERROR);
		free((*prv)->buf);
		(*prv)->len = (*prv)->len + tmp_len;
	}
	(*prv)->buf = joined;
	return (GNL_SUCCESS);
}

int		gnl_clean(t_buf **prv, char *tmp_buf, int status)
{
	if (prv && *prv)
	{
		free((*prv)->buf);
		free(*prv);
		*prv = 0;
	}
	if (tmp_buf)
		free(tmp_buf);
	return (status);
}

/*
** int get_next_line(int fd, char **line);
**
** 1) Check fd, line, BUFFER_SIZE
** 2) Check prev buffer already has line
** 3) Allocate memory to temp buffer(BUFFER_SIZE + 1)
** 4) Loop : read file to temp buffer
** [4 - 1] Append temp buffer to prev buffer
** [4 - 2] Check prev buffer
** 5) Exit loop and return with condition
** [5 - 1] If (tmp_len < 0) -> ERROR
** [5 - 2] Else EOF reached -> EOF
*/

int		get_next_line(int fd, char **line)
{
	static t_buf	*prvs[OPEN_MAX] = { 0 };
	char			*tmp_buf;
	ssize_t			tmp_len;
	char			*endl_pos;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (GNL_ERROR);
	if (prvs[fd] && (endl_pos = ft_strchr(prvs[fd]->buf, '\n')))
		return (gnl_get_line(&prvs[fd], endl_pos, line));
	if (!(tmp_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (GNL_ERROR);
	while ((tmp_len = read(fd, tmp_buf, BUFFER_SIZE)) > 0)
	{
		if (gnl_append_buf(&prvs[fd], tmp_buf, tmp_len) == GNL_ERROR)
			return (gnl_clean(0, tmp_buf, GNL_ERROR));
		if ((endl_pos = ft_strchr(prvs[fd]->buf, '\n')) != 0)
			break ;
	}
	if (tmp_len < 0)
		return (gnl_clean(&prvs[fd], tmp_buf, GNL_ERROR));
	if (gnl_get_line(&prvs[fd], endl_pos, line) == GNL_SUCCESS)
		return (gnl_clean(0, tmp_buf, GNL_SUCCESS));
	else
		return (gnl_clean(&prvs[fd], tmp_buf, GNL_EOF));
}
