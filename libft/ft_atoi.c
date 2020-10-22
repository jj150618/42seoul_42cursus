/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:44:21 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/21 14:45:43 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int j;
	int value;
	int sign;

	i = 0;
	sign = 1;
	value = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
		value = value * 10 + str[i++] - '0';
	j = i - j;
	if (j > 19 && sign == -1)
		return (0);
	if (j > 19 && sign == 1)
		return (-1);
	return (value * sign);
}
