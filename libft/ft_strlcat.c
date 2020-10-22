/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:49:57 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/21 16:27:53 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_n;
	size_t	src_n;
	size_t	i;

	dest_n = ft_strlen(dest);
	src_n = ft_strlen(src);
	i = 0;
	while (src[i] && n > dest_n + i + 1)
	{
		dest[dest_n + i] = src[i];
		i++;
	}
	dest[dest_n + i] = '\0';
	if (dest_n > n)
		return (n + src_n);
	else
		return (dest_n + src_n);
}
