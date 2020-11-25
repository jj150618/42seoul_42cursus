/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:48:10 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/14 15:11:38 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	i = 0;
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	while (i < len && s[start + (unsigned int)i])
	{
		res[i] = s[start + (unsigned int)i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
