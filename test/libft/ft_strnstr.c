/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 11:16:44 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/14 16:40:54 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t num)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!*tofind)
		return ((char*)str);
	i = 0;
	len = ft_strlen(tofind);
	while (str[i] && i < num)
	{
		j = 0;
		while (str[i + j] == tofind[j] && i + j < num)
		{
			if (j == len - 1)
				return ((char*)&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
