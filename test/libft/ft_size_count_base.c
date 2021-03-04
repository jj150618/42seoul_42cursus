/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_count_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:49:20 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/14 16:46:39 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size_count_base(unsigned long long lln, unsigned int base)
{
	size_t	count;

	count = 1;
	while (lln >= base)
	{
		count++;
		lln /= base;
	}
	return (count);
}
