/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:12:42 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/21 14:36:22 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	cnt_trim(char const *s, char const *set)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (is_set(s[s_len - i - 1], set))
		i++;
	return (s_len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	cnt;
	size_t	len;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	cnt = 0;
	while (is_set(s1[cnt], set))
		cnt++;
	if (cnt == ft_strlen(s1))
		return (ft_strdup(""));
	len = cnt_trim(s1 + cnt, set);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + cnt, len + 1);
	return (res);
}
