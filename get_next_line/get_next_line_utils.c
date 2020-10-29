/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:59:13 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/29 11:13:57 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	if (!src)
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!temp)
		return (NULL);
	ft_strncpy(temp, s1, i);
	ft_strncpy(temp + i, s2, j);
	temp[i + j] = '\0';
	return (temp);
}

char	*ft_strndup(char *s1, size_t n)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (n + 1));
	if (!temp)
		return (NULL);
	ft_strncpy(temp, s1, n);
	temp[n] = '\0';
	return (temp);
}
