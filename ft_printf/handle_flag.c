/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:52:40 by yewlee            #+#    #+#             */
/*   Updated: 2020/11/25 12:04:49 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_flag1(t_format *t, char *str)
{
	int		start;
	char	*suffix;

	start = 0;
	if (!(suffix = (char*)malloc(sizeof(char) * (4))))
	{
		t->error = 1;
		return (0);
	}
	if (t->suffix)
		suffix[start++] = '-';
	else if (t->is_plus && ft_strchr("di", t->conversion))
		suffix[start++] = '+';
	else if (t->is_space && ft_strchr("di", t->conversion))
		suffix[start++] = ' ';
	handle_flag2(t, str, &suffix, start);
	t->suffix = suffix;
	return (ft_strlen(suffix));
}

void	handle_flag2(t_format *t, char *str, char **suffix, int start)
{
	if (t->is_sharp && t->conversion == 'o' && ft_strcmp(str, "0") && \
		ft_strcmp(str, ""))
		(*suffix)[start++] = '0';
	else if ((t->is_sharp && ft_strchr("xX", t->conversion) && \
			ft_strcmp(str, "0") && ft_strcmp(str, "")) || \
			t->conversion == 'p')
	{
		if (t->conversion == 'p' || t->conversion == 'x')
			ft_strcpy((*suffix) + start, "0x");
		else
			ft_strcpy((*suffix) + start, "0X");
		start += 2;
	}
	(*suffix)[start] = '\0';
}

void	handle_prec1(char **str, t_format *t, int *len, int *s_len)
{
	int		max;
	char	*temp;

	max = (t->precision > *len) ? t->precision : *len;
	temp = *str;
	if (!(*str = (char*)malloc(sizeof(char) * (*s_len + max + 1))))
	{
		t->error = 1;
		return ;
	}
	if (*s_len)
		ft_strcpy(*str, t->suffix);
	while (t->precision > *len)
	{
		(*str)[(*s_len)++] = '0';
		(*len)++;
	}
	ft_strcpy((*str) + (*s_len), temp);
	*s_len = 0;
	*len = ft_strlen(*str);
	free(temp);
}

void	handle_prec2(char **str, t_format *t, int *len)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *str;
	if (t->precision == -1)
		*str = ft_strdup("");
	else if (t->precision < *len)
		*str = ft_substr(temp, 0, t->precision);
	if (!(*str))
	{
		t->error = 1;
		return ;
	}
	*len = ft_strlen(*str);
	free(temp);
}
