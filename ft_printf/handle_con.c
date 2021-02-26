/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_con.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:52:40 by yewlee            #+#    #+#             */
/*   Updated: 2020/11/25 11:59:48 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_con(t_format *t, va_list *lst, int *len, int *count)
{
	char	*str;

	str = NULL;
	if (ft_strchr("diu", t->conversion))
		str = handle_con1(t, lst, len);
	else if (ft_strchr("poxX", t->conversion))
		str = handle_con2(t, lst, len);
	else if (ft_strchr("cs%", t->conversion))
		str = handle_con3(t, lst, len);
	else
		*va_arg(*lst, int*) = *count;
	return (str);
}

char	*handle_con1(t_format *t, va_list *lst, int *len)
{
	long long	d;
	char		*str;

	str = NULL;
	if (t->conversion == 'd' || t->conversion == 'i')
	{
		d = (t->length) ? handle_length1(t, lst) : va_arg(*lst, int);
		if (d < 0)
		{
			t->suffix = "-";
			d *= (-1);
		}
	}
	else
		d = (t->length) ? handle_length2(t, lst) : va_arg(*lst, unsigned int);
	if (!(str = ft_ulltoa((unsigned long long)d)))
		return (handle_malloc_fail(t));
	handle_exception(t, &str, len);
	*len = ft_strlen(str);
	return (str);
}

char	*handle_con2(t_format *t, va_list *lst, int *len)
{
	int					i;
	unsigned int		base;
	unsigned long long	d;
	char				*str;

	i = 0;
	base = (t->conversion == 'o') ? 8 : 16;
	if (t->conversion == 'p')
		d = va_arg(*lst, unsigned long);
	else
		d = (t->length) ? handle_length2(t, lst) : va_arg(*lst, unsigned int);
	if (!(str = ft_ulltoa_base(d, base)))
		return (handle_malloc_fail(t));
	while (t->conversion == 'X' && str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	handle_exception(t, &str, len);
	*len = ft_strlen(str);
	return (str);
}

char	*handle_con3(t_format *t, va_list *lst, int *len)
{
	char	c[2];
	char	*temp;
	char	*str;

	if (t->conversion == 'c')
	{
		c[0] = (char)va_arg(*lst, int);
		c[1] = '\0';
		str = ft_strdup(c);
	}
	else if (t->conversion == 's')
	{
		temp = va_arg(*lst, char*);
		if (!temp)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(temp);
	}
	else
		str = ft_strdup("%");
	if (!str)
		return (handle_malloc_fail(t));
	*len = ft_strlen(str);
	handle_exception(t, &str, len);
	return (str);
}
