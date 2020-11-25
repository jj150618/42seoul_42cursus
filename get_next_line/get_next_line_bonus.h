/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 08:28:39 by junghkim          #+#    #+#             */
/*   Updated: 2020/11/25 08:28:41 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4242
# endif

typedef struct		s_list
{
	int				fd;
	char			*buff;
	struct s_list	*next;
	char			temp_buff[BUFFER_SIZE + 1];
}					t_list;

int					get_next_line(int fd, char **line);

void				free_list(t_list **head, int fd);
t_list				*find_list(t_list *lst_buff, int fd);
t_list				*new_list(int fd);
int					find_nl(char **line, t_list *lst_buf);

size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strjoin(char **s1, char *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);

#endif
