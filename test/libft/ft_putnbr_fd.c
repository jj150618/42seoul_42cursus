/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:51:40 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/03 12:51:41 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	lln;

	lln = n;
	if (lln < 0)
	{
		lln = -lln;
		ft_putchar_fd('-', fd);
	}
	if (lln >= 10)
		ft_putnbr_fd(lln / 10, fd);
	ft_putchar_fd(lln % 10 + '0', fd);
}
