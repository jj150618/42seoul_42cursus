/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 09:40:47 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/03 10:23:57 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (((unsigned char*)ptr1)[i] != ((unsigned char*)ptr2)[i])
			return (((unsigned char*)ptr1)[i] - ((unsigned char*)ptr2)[i]);
		i++;
	}
	return (0);
}
