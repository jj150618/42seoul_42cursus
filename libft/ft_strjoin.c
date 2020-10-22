/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 07:36:08 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/21 14:35:09 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, s1, i + 1);
	ft_strlcat(temp, s2, i + j + 1);
	return (temp);
}
