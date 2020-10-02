/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:17:01 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/02 14:37:21 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dest);
}
