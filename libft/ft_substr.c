/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:56:39 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/21 07:43:16 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	i = ft_strlen(s);
	if (start > i)
	{
		temp[0] = '\0';
		return (temp);
	}
	ft_strlcpy(temp, s + start, len + 1);
	return (temp);
}
