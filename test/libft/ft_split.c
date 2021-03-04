/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:49:06 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/14 15:34:18 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	words_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				count++;
		}
		i++;
	}
	return (count);
}

size_t	words_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

void	*ft_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	len;
	char	**res;

	if (!s)
		return (0);
	if (!(res = (char**)malloc(sizeof(char*) * (words_count(s, c) + 1))))
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		len = words_len(&s[i], c);
		if (len > 0)
		{
			if (!(res[count++] = ft_substr(s, (unsigned int)i, len)))
				return (ft_free(res));
			i += len;
		}
		else
			i++;
	}
	res[count] = NULL;
	return (res);
}
