/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:48:49 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/02 14:44:48 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	i = 0;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		if (temp_src[i] == c)
			return (dest + i + 1);
	}
	return (NULL);
}
