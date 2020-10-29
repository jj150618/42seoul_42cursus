/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:42:14 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/29 10:43:54 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	char	*cast_str;
	char	*cast_to_find;

	cast_str = (char *)str;
	cast_to_find = (char *)to_find;
	if (!*to_find)
		return ((char *)str);
	i = -1;
	while (cast_str[++i] && i < n)
	{
		j = 0;
		if (cast_str[i] == cast_to_find[j])
			while (cast_str[i + j] == cast_to_find[j] && i + j < n)
			{
				if (cast_to_find[j + 1] == '\0')
					return (cast_str + i);
				j++;
			}
	}
	return (NULL);
}
