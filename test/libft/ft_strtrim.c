/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:48:47 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/14 16:41:06 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		to_trim(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1)
		return (0);
	if (!*s1)
		return (ft_strdup(""));
	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && to_trim(s1[start], s2))
		start++;
	while (to_trim(s1[end], s2) && start < end)
		end--;
	if (!(res = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (0);
	while (start <= end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
