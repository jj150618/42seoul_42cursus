/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:21:26 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/03 09:05:17 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

/*
** Constant
*/

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# define GNL_FAIL 2
# define GNL_SUCCESS 1
# define GNL_EOF 0
# define GNL_ERROR -1

/*
** Struct
*/

typedef struct		s_buf
{
	char			*buf;
	size_t			len;
}					t_buf;

/*
** Main function
*/

int					gnl_get_line(t_buf **prv, char *endl_pos, char **line);

int					gnl_append_buf(t_buf **prv, char *tmp_buf, ssize_t tmp_len);

int					gnl_clean(t_buf **prv, char *tmp_buf, int status);

int					get_next_line(int fd, char **line);

/*
** Utility function
*/

char				*ft_strchr(const char *s, int c);

ssize_t				gnl_get_len(const char *s, ssize_t s_len);

char				*ft_strndup(const char *s1, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

char				*gnl_join(char const *s1, size_t s1_len,
							char const *s2, size_t s2_len);

#endif
