/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:47:43 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/22 14:00:56 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*temp;
	int		i;
	int		j;
	int		temp_n;

	i = 0;
	j = ft_numlen(n);
	temp_n = n;
	temp = (char *)malloc(sizeof(char) * (j + 1));
	if (!temp)
		return (NULL);
	while (i < j)
	{
		if (temp_n < 0)
			temp[j - i - 1] = temp_n % 10 * (-1) + '0';
		else
			temp[j - i - 1] = temp_n % 10 + '0';
		i++;
		temp_n /= 10;
	}
	if (n < 0)
		temp[0] = '-';
	temp[j] = '\0';
	return (temp);
}
