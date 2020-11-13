/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:07:59 by junghkim          #+#    #+#             */
/*   Updated: 2020/11/03 12:29:41 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4242
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif


int		get_next_line(int fd, char **line);

char	*ft_strchr(char *str, int c);
char	*ft_strncpy(char *dest, char *src, size_t n);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1, size_t n);

#endif
