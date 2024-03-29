/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:07:59 by junghkim          #+#    #+#             */
/*   Updated: 2020/11/25 14:52:26 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4242
# endif

typedef struct		s_lists
{
	int				fd;
	char			*buff;
	struct s_lists	*next;
	char			temp_buff[BUFFER_SIZE + 1];
}					t_lists;

int					get_next_line(int fd, char **line);

void				free_list(t_lists **head, int fd);
t_lists				*find_list(t_lists *lst_buff, int fd);
t_lists				*new_list(int fd);
int					find_nl(char **line, t_lists *lst_buf);

size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strjoin(char **s1, char *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);

#endif
