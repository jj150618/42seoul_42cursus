/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:44:25 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/14 13:42:16 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	if (src > dest)
		ft_memcpy(dest, src, num);
	else
	{
		i = num;
		while (i > 0)
		{
			((char*)dest)[i - 1] = ((char*)src)[i - 1];
			i--;
		}
	}
	return (dest);
}
