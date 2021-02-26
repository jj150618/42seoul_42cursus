/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:09:03 by junghkim          #+#    #+#             */
/*   Updated: 2020/11/25 13:09:06 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_format(char *format, int i)
{
	while (format[++i])
		if (ft_strchr("cspdiuxX%", format[j]) != 0) // cspdiouxXn%
			return (j);
	return (-1);
}

int		ft_printf(const char *format, ...)
{
	va_list	lst;
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	va_start(lst, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = find_format((char*)format, i);
			if (j == -1 || parse((char*)format + i + 1, &lst, &count, j - i))
				return (-1);
			i = j + 1;
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(lst);
	return (count);
}
