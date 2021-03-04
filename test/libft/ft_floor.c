/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:11:19 by yewlee            #+#    #+#             */
/*   Updated: 2020/06/29 16:17:27 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_floor(double num)
{
	double	res;
	double	fr;

	res = (long long)num;
	fr = num - res;
	if (fr < 0)
		return (res - 1);
	else
		return (res);
}
