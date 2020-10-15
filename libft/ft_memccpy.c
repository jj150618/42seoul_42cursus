/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:48:49 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/14 14:12:58 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*cast_dest;
	unsigned char	*cast_src;

	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	while (0 < n--)
	{
		*(cast_dest++) = *(cast_src++);
		if (*cast_src == c)
			return ((void *)(cast_dest + 1));
	}
	return (NULL);
}
