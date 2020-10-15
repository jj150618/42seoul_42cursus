/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:15:11 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/14 14:30:22 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*cast_str1;
	unsigned char	*cast_str2;

	*cast_str1 = (unsigned char *)str1;
	*cast_str2 = (unsigned char *)str2;
	while (0 < n--)
		if (*(cast_str1++) != *(cast_str2++))
			return (*cast_str1 - *cast_str2);
	return (NULL);
}
