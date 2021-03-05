

#include "ft_printf.h"

int		handle_flag1(t_info *info)
{
	int		start;
	char	*suffix;

	start = 0;
	if (!(suffix = (char*)malloc(sizeof(char) * (4))))
	{
		info->error = 1;
		return (0);
	}
	if (info->suffix)
		suffix[start++] = '-';
	handle_flag2(info, &suffix, start);
	info->suffix = suffix;
	return (ft_strlen(suffix));
}

void	handle_flag2(t_info *info, char **suffix, int start)
{
	if (info->conversion == 'p')
	{
		ft_strcpy((*suffix) + start, "0x");
		start += 2;
	}
	(*suffix)[start] = '\0';
}

void	handle_prec1(char **str, t_info *info, int *len, int *s_len)
{
	int		max;
	char	*temp;

	max = (info->precision > *len) ? info->precision : *len;
	temp = *str;
	if (!(*str = (char*)malloc(sizeof(char) * (*s_len + max + 1))))
	{
		info->error = 1;
		return ;
	}
	if (*s_len)
		ft_strcpy(*str, info->suffix);
	while (info->precision > *len)
	{
		(*str)[(*s_len)++] = '0';
		(*len)++;
	}
	ft_strcpy((*str) + (*s_len), temp);
	*s_len = 0;
	*len = ft_strlen(*str);
	free(temp);
}

void	handle_prec2(char **str, t_info *info, int *len)
{
	char	*temp;

	temp = *str;
	if (info->precision == -1)
		*str = ft_strdup("");
	else if (info->precision < *len)
		*str = ft_substr(temp, 0, info->precision);
	if (!(*str))
	{
		info->error = 1;
		return ;
	}
	*len = ft_strlen(*str);
	free(temp);
}
