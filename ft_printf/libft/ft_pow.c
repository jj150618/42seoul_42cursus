

#include "libft.h"

double	ft_pow(double num, int pow)
{
	int		i;
	double	res;

	i = 0;
	res = 1;
	if (!pow)
		return (1);
	while (i < pow)
	{
		res *= num;
		i++;
	}
	return (res);
}
