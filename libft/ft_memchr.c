/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:02:45 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/14 14:13:56 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*cast_str;

	cast_str = (unsigned char *)str;
	while (0 < n--)
		if (*(cast_str++) == c)
			return ((void *)cast_str);
	return (0);
}
