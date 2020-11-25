/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:49:20 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/14 16:46:39 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa(unsigned long long n)
{
	size_t		size;
	size_t		end;
	char		*res;

	end = 0;
	size = ft_size_ucount(n);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	res[size] = '\0';
	while (size > 0 && --size >= end)
	{
		res[size] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
