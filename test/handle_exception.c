/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exception.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:52:40 by yewlee            #+#    #+#             */
/*   Updated: 2020/11/25 12:08:05 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_malloc_fail(t_format *t)
{
	t->error = 1;
	return (NULL);
}

int		handle_return_fail(char *str, char *suffix)
{
	if (str)
		free(str);
	if (suffix)
		free(suffix);
	return (-1);
}

void	handle_exception(t_format *t, char **str, int *len)
{
	char	*temp;

	if (ft_strchr("dioupxX", t->conversion) && !ft_strcmp(*str, "0") \
			&& t->precision == -1)
	{
		temp = *str;
		*str = ft_strdup("");
		free(temp);
	}
	else if (t->conversion == 'c' && !(*len))
		*len = 1;
}
