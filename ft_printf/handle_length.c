/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:52:40 by yewlee            #+#    #+#             */
/*   Updated: 2020/10/15 01:41:12 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			handle_length1(t_format *t, va_list *lst)
{
	if (!ft_strcmp(t->length, "hh"))
		return ((char)va_arg(*lst, int));
	else if (!ft_strcmp(t->length, "h"))
		return ((short)va_arg(*lst, int));
	else if (!ft_strcmp(t->length, "l"))
		return (va_arg(*lst, long));
	else
		return (va_arg(*lst, long long));
}

unsigned long long	handle_length2(t_format *t, va_list *lst)
{
	if (!ft_strcmp(t->length, "hh"))
		return ((unsigned char)va_arg(*lst, unsigned int));
	else if (!ft_strcmp(t->length, "h"))
		return ((unsigned short)va_arg(*lst, unsigned int));
	else if (!ft_strcmp(t->length, "l"))
		return (va_arg(*lst, unsigned long));
	else
		return (va_arg(*lst, unsigned long long));
}
