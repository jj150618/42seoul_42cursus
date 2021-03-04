

#include "ft_printf.h"

int		handle_flag(t_info *t, char *str)
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
	suffix[start] = '\0';
	t->suffix = suffix;
	return (ft_strlen(suffix));
}

void	handle_prec1(char **str, t_info *t, int *len, int *s_len)
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

void	handle_prec2(char **str, t_info *t, int *len)
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
