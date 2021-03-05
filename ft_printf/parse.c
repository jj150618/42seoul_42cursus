

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->conversion = 0;
	info->is_minus = 0;
	info->suffix = 0;
	info->is_zero = 0;
	info->width = 0;
	info->precision = 0;
	info->error = 0;
}

int		parse(char *format, va_list *ap, int *count, int end)
{
	int			i;
	t_info		info;

	i = 0
	
	;
	init_info(&info);
	info.conversion = format[end - 1];
	while (i < end)
	{
		if (ft_strchr("-0", format[i]))
			parse_flag(&info, format[i]);
		else if (format[i] == '*')
			parse_star(&info, ap, format, i);
		else if (format[i] == '.' || (format[i] != '0' && \
				ft_isdigit(format[i])))
		{
			parse_wp(&info, format, &i, end);
			continue ;
		}
		i++;
	}
	return (print_format(&info, ap, count));
}

void	parse_flag(t_info *info, char c)
{
	if (c == '-')
		info->is_minus = 1;
	else if (c == '0')
		info->is_zero = 1;
}

void	parse_star(t_info *info, va_list *ap, char *format, int start)
{
	if (format[start - 1] == '.')
	{
		info->precision = va_arg(*ap, int);
		if (info->precision < 0)
			info->precision = 0;
		else if (!info->precision)
			info->precision = -1;
	}
	else
	{
		info->width = va_arg(*ap, int);
		if (info->width < 0)
		{
			info->width *= (-1);
			info->is_minus = 1;
		}
	}
}

void	parse_wp(t_info *info, char *format, int *start, int end)
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
			info->precision = -1;
		else
			info->precision = sign ? 0 : res;
	}
	else
	{
		while (ft_isdigit(format[*start]) && (*start < end))
		{
			res = 10 * res + format[*start] - '0';
			(*start)++;
		}
		info->width = res;
	}
}
