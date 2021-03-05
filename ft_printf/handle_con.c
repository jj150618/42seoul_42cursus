

#include "ft_printf.h"

char	*handle_con(t_info *info, va_list *ap, int *len)
{
	char	*str;

	str = NULL;
	if (ft_strchr("diu", info->conversion))
		str = handle_con1(info, ap, len);
	else if (ft_strchr("pxX", info->conversion))
		str = handle_con2(info, ap, len);
	else if (ft_strchr("cs%", info->conversion))
		str = handle_con3(info, ap, len);
	return (str);
}

char	*handle_con1(t_info *info, va_list *ap, int *len)
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
		return (handle_malloc_fail(info));
	handle_exception(info, &str, len);
	*len = ft_strlen(str);
	return (str);
}

char	*handle_con2(t_info *info, va_list *ap, int *len)
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
		return (handle_malloc_fail(info));
	while (info->conversion == 'X' && str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	handle_exception(info, &str, len);
	*len = ft_strlen(str);
	return (str);
}

char	*handle_con3(t_info *info, va_list *ap, int *len)
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
		return (handle_malloc_fail(info));
	*len = ft_strlen(str);
	handle_exception(info, &str, len);
	return (str);
}