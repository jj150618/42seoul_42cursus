/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:52:40 by yewlee            #+#    #+#             */
/*   Updated: 2020/11/25 11:55:23 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_wp(t_format *t, char *format, int *start, int end)
{
	int	res;
	int	sign;

	res = 0;
	if (format[*start] == '.')
	{
		sign = (format[++(*start)] == '-') ? 1 : 0;
		if (sign)
			(*start)++;
		while (ft_isdigit(format[*start]) && (*start < end))
			res = 10 * res + format[(*start)++] - '0';
		if (!res)
			t->precision = -1;
		else
			t->precision = sign ? 0 : res;
	}
	else
	{
		while (ft_isdigit(format[*start]) && (*start < end))
		{
			res = 10 * res + format[*start] - '0';
			(*start)++;
		}
		t->width = res;
	}
}

void	parse_length(t_format *t, char *format, int *start)
{
	if (format[*start] == 'h')
	{
		if (format[(*start) + 1] == 'h')
		{
			t->length = "hh";
			(*start)++;
		}
		else
			t->length = "h";
	}
	else
	{
		if (format[(*start) + 1] == 'l')
		{
			t->length = "ll";
			(*start)++;
		}
		else
			t->length = "l";
	}
}
