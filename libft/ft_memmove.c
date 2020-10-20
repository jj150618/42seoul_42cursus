/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:48:33 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/20 10:13:02 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cast_dest;
	unsigned char	*cast_src;

	if (!dest && !src)
		return (NULL);
	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	if (cast_dest > cast_src)
		while (0 < n--)
			*(cast_dest + n) = *(cast_src + n);
	else
		while (0 < n--)
			*(cast_dest++) = *(cast_src++);
	return (dest);
}
