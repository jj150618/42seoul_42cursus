/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:59:13 by junghkim          #+#    #+#             */
/*   Updated: 2020/11/25 13:36:47 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if ((!dest && !src))
		return (0);
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t j;
	size_t i;

	j = 0;
	i = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j] && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dest[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*new_str;
	size_t	join_str_len;

	if (!s1 || !s2)
		return (NULL);
	join_str_len = ft_strlen(*s1) + ft_strlen(s2) + 1;
	if (!(new_str = (char*)malloc(join_str_len)))
		return (NULL);
	ft_strlcpy(new_str, *s1, join_str_len);
	ft_strlcat(new_str, s2, join_str_len);
	free(*s1);
	return (new_str);
}
