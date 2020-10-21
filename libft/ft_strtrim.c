/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:12:42 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/21 09:58:40 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char const *set, char c)
{
	int i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*temp;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start])
		if (ft_checkset(set, s1[start]))
			start++;
		else
			break ;
	while (0 <= end)
		if (ft_checkset(set, s1[end]))
			end--;
		else
			break ;
	if (start > end)
		return (ft_strdup(""));
	temp = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, &s1[start], end - start + 2);
	return (temp);
}
