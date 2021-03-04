/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_ucount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:49:20 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/14 16:46:39 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size_ucount(unsigned long long lln)
{
	size_t	count;

	count = 1;
	while (lln >= 10)
	{
		count++;
		lln /= 10;
	}
	return (count);
}
