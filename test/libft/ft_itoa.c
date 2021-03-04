/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:49:20 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/14 16:46:39 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t		size;
	size_t		end;
	long long	lln;
	char		*res;

	end = 0;
	lln = n;
	size = ft_size_count(lln);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (lln < 0)
	{
		lln = -lln;
		end = 1;
		res[0] = '-';
	}
	res[size] = '\0';
	while (size > 0 && --size >= end)
	{
		res[size] = lln % 10 + '0';
		lln /= 10;
	}
	return (res);
}
