/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:52:40 by yewlee            #+#    #+#             */
/*   Updated: 2020/11/25 11:56:33 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_with_flag(t_format *t, char *str, int *len, int s_len)
{
	int		temp;
	int		flag;
	char	c;

	flag = (t->is_zero && !t->precision && ft_strchr("diuxXs", t->conversion));
	temp = *len;
	c = (flag || (t->is_zero && t->conversion == '%')) ? '0' : ' ';
	while (!t->is_minus && t->width > (*len + s_len))
	{
		if (flag == 1)
		{
			write(1, t->suffix, s_len);
			flag = -1;
		}
		(*len) += write(1, &c, 1);
	}
	if (flag != -1)
		write(1, t->suffix, s_len);
	write(1, str, temp);
	while (t->is_minus && t->width > (*len + s_len))
		(*len) += write(1, " ", 1);
	(*len) += s_len;
}

int		print_format(t_format *t, va_list *lst, int *count)
{
	int		len;
	int		s_len;
	char	*str;

	len = 0;
	str = handle_con(t, lst, &len, count);
	s_len = handle_flag1(t, str);
	if (t->error)
		return (handle_return_fail(str, t->suffix));
	if ((ft_strchr("diuxX", t->conversion) && t->precision > len) || \
		t->conversion == 'p')
		handle_prec1(&str, t, &len, &s_len);
	else if (t->conversion == 's' && t->precision && t->precision < len)
		handle_prec2(&str, t, &len);
	if (t->error)
		return (handle_return_fail(str, t->suffix));
	else if (str)
	{
		print_with_flag(t, str, &len, s_len);
		free(str);
	}
	free(t->suffix);
	(*count) += len;
	return (0);
}
