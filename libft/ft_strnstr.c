/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:42:14 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/14 16:52:20 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (!to_find)
		return (str);
	i = -1;
	while (str[++i] && i < n)
	{
		j = 0;
		if (str[i] == to_find[j])
			while (str[i + j] == to_find[j])
			{
				if (to_find[j + 1] = '\0')
					return ((char *)(str + i));
				j++;
			}
		i++;
	}
	return (NULL);
}
