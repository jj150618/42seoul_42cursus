/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:52:40 by yewlee            #+#    #+#             */
/*   Updated: 2020/11/25 11:51:32 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_format *t)
{
	t->conversion = 0;
	t->length = 0;
	t->suffix = 0;
	t->is_minus = 0;
	t->is_plus = 0;
	t->is_space = 0;
	t->is_sharp = 0;
	t->is_zero = 0;
	t->width = 0;
	t->precision = 0;
	t->error = 0;
}

int		parse(char *format, va_list *lst, int *count, int end)
{
	int			i;
	t_format	t;

	i = 0;
	init(&t);
	t.conversion = format[end - 1];
	while (i < end)
	{
		if (ft_strchr("-0# +", format[i]))
			parse_flag(&t, format[i]);
		else if (format[i] == '*')
			parse_star(&t, lst, format, i);
		else if (format[i] == '.' || (format[i] != '0' && \
				ft_isdigit(format[i])))
		{
			parse_wp(&t, format, &i, end);
			continue ;
		}
		else if (format[i] == 'l' || format[i] == 'h')
			parse_length(&t, format, &i);
		i++;
	}
	return (print_format(&t, lst, count));
}

void	parse_flag(t_format *t, char c)
{
	if (c == '-')
		t->is_minus = 1;
	else if (c == '0')
		t->is_zero = 1;
	else if (c == '#')
		t->is_sharp = 1;
	else if (c == ' ')
		t->is_space = 1;
	else if (c == '+')
		t->is_plus = 1;
}

void	parse_star(t_format *t, va_list *lst, char *format, int start)
{
	if (format[start - 1] == '.')
	{
		t->precision = va_arg(*lst, int);
		if (t->precision < 0)
			t->precision = 0;
		else if (!t->precision)
			t->precision = -1;
	}
	else
	{
		t->width = va_arg(*lst, int);
		if (t->width < 0)
		{
			t->width *= (-1);
			t->is_minus = 1;
		}
	}
}
