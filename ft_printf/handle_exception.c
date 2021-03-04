
#include "ft_printf.h"

char	*handle_malloc_fail(t_info *info)
{
	info->error = 1;
	return (NULL);
}

int		handle_return_fail(char *str, char *suffix)
{
	if (str)
		free(str);
	if (suffix)
		free(suffix);
	return (-1);
}

void	handle_exception(t_info *info, char **str, int *len)
{
	char	*temp;

	if (ft_strchr("diupxX", info->conversion) && !ft_strcmp(*str, "0") \
			&& info->precision == -1)
	{
		temp = *str;
		*str = ft_strdup("");
		free(temp);
	}
	else if (info->conversion == 'c' && !(*len))
		*len = 1;
}
