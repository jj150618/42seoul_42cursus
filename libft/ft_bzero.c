/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 22:27:09 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/02 13:15:37 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		temp[i] = '0';
		i++;
	}
}
