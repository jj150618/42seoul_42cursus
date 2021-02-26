/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:02:45 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/20 10:43:26 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*cast_str;

	cast_str = (unsigned char *)str;
	while (0 < n--)
		if (*(cast_str++) == (unsigned char)c)
			return ((void *)(cast_str - 1));
	return (NULL);
}
