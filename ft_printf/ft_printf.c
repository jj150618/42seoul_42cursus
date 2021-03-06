/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:09:03 by junghkim          #+#    #+#             */
/*   Updated: 2021/03/06 14:29:19 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_format(const char *format, int i)
{
	while (format[++i])
		if (ft_strchr(TYPE, format[i]) != 0)
			return (i);
	return (-1);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = check_format(format, i);
			if (j == -1 || parse((char*)format + i + 1, &ap, &count, j - i))
				return (-1);
			i = j + 1;
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (count);
}
