/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:49:20 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/14 16:46:39 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size_count(long long lln)
{
	size_t	count;

	count = 1;
	if (lln < 0)
	{
		count = 2;
		lln = -lln;
	}
	while (lln >= 10)
	{
		count++;
		lln /= 10;
	}
	return (count);
}
