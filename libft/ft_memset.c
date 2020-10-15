/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 20:30:47 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/14 15:03:33 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int src, size_t n)
{
	unsigned char	*cast_dest;

	cast_dset = (unsigned char *)dest;
	while (0 < n--)
		*(cast_dest++) = src;
	return (dest);
}
