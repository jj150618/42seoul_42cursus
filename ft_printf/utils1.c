/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:41:07 by junghkim          #+#    #+#             */
/*   Updated: 2021/03/06 14:41:37 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*control_malloc_fail(t_info *info)
{
	info->error = 1;
	return (NULL);
}

int		control_return_fail(char *str, char *suffix)
{
	if (str)
		free(str);
	if (suffix)
		free(suffix);
	return (-1);
}

void	control_exception(t_info *info, char **str, int *len)
{
	char	*temp;

	if (ft_strchr("diupxX", info->conversion) && !ft_strcmp(*str, "0") \
			&& info->precision == -1)
	{
		temp = *str;
		*str = ft_strdup("");
		free(temp);
	}
	else if (info->conversion == 'c' && !(*len))
		*len = 1;
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
