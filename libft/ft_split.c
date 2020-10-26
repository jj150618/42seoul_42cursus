/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:59:26 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/27 00:12:19 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_str(char const *s, char c)
{
	int i;
	int cnt;

	cnt = 0;
	i = 0;
	if (s[i] && s[i] != c)
	{
		cnt++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != '\0')
			if (s[i + 1] != c)
				cnt++;
		i++;
	}
	return (cnt);
}

static char			*ft_strdup_n(char const *s, unsigned int n)
{
	unsigned int	i;
	char			*temp;

	temp = (char *)malloc(sizeof(char) * (n + 1));
	if (!temp)
		return (NULL);
	i = -1;
	while (++i < n)
		temp[i] = s[i];
	temp[n] = '\0';
	return (temp);
}

static void			ft_put_str(char **strs, char const *s, char c)
{
	int i;
	int j;
	int cnt;
	int size;

	i = -1;
	j = 1;
	cnt = 0;
	if (s[++i] && s[i] != c)
		j = 0;
	while (s[i])
		if (s[++i] == c)
		{
			size = i - j;
			if (size > 0)
				strs[cnt++] = ft_strdup_n(s + j, size);
			j = i + 1;
		}
	size = i - j;
	if (size > 0)
		strs[cnt] = ft_strdup_n(s + j, size);
}

static void			strs_free(char **strs)
{
	int i;

	i = -1;
	while (strs[++i] != NULL)
		free(strs[i]);
	free(strs);
}

char				**ft_split(char const *s, char c)
{
	unsigned int	cnt;
	unsigned int	i;
	char			**strs;

	if (!s)
		return (NULL);
	cnt = count_str(s, c);
	if (!(strs = (char **)malloc(sizeof(char *) * (cnt + 1))))
		return (NULL);
	if (!c && s[0])
	{
		free(strs);
		strs = (char **)malloc(sizeof(char *) * 2);
		i = ft_strlen(s);
		strs[0] = ft_strdup_n(s, i);
		strs[1] = 0;
		return (strs);
	}
	ft_put_str(strs, s, c);
	i = 0;
	while (i < cnt)
		if (strs[i++] == NULL)
			strs_free(strs);
	strs[cnt] = 0;
	return (strs);
}
