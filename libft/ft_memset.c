/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 20:30:47 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/01 22:23:07 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int src, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = -1;
	temp = (unsigned char *)dest;
	while (++i < len)
		temp[i] = src;
	return (dest);
}
