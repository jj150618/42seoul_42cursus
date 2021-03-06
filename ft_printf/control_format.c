

#include "ft_printf.h"

char	*control_format(t_info *info, va_list *ap, int *len)
{
	char	*str;

	str = NULL;
	if (ft_strchr("diu", info->conversion))
		str = control_format1(info, ap, len);
	else if (ft_strchr("pxX", info->conversion))
		str = control_format2(info, ap, len);
	else if (ft_strchr("cs%", info->conversion))
		str = control_format3(info, ap, len);
	return (str);
}

char	*control_format1(t_info *info, va_list *ap, int *len)
{
	long long	d;
	char		*str;

	str = NULL;
	if (info->conversion == 'd' || info->conversion == 'i')
	{
		d = va_arg(*ap, int);
		if (d < 0)
		{
			info->suffix = "-";
			d *= (-1);
		}
	}
	else
		d = va_arg(*ap, unsigned int);
	if (!(str = ft_ulltoa((unsigned long long)d)))
		return (control_malloc_fail(info));
	control_exception(info, &str, len);
	*len = ft_strlen(str);
	return (str);
}

char	*control_format2(t_info *info, va_list *ap, int *len)
{
	int					i;
	unsigned int		base;
	unsigned long long	d;
	char				*str;

	i = 0;
	base = 16;
	if (info->conversion == 'p')
		d = va_arg(*ap, unsigned long);
	else
		d = va_arg(*ap, unsigned int);
	if (!(str = ft_ulltoa_base(d, base)))
		return (control_malloc_fail(info));
	while (info->conversion == 'X' && str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	control_exception(info, &str, len);
	*len = ft_strlen(str);
	return (str);
}

char	*control_format3(t_info *info, va_list *ap, int *len)
{
	char	c[2];
	char	*temp;
	char	*str;

	if (info->conversion == 'c')
	{
		c[0] = (char)va_arg(*ap, int);
		c[1] = '\0';
		str = ft_strdup(c);
	}
	else if (info->conversion == 's')
	{
		temp = va_arg(*ap, char*);
		if (!temp)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(temp);
	}
	else
		str = ft_strdup("%");
	if (!str)
		return (control_malloc_fail(info));
	*len = ft_strlen(str);
	control_exception(info, &str, len);
	return (str);
}