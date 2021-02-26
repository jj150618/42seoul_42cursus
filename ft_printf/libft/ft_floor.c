

#include "libft.h"

double	ft_floor(double num)
{
	double	res;
	double	fr;

	res = (long long)num;
	fr = num - res;
	if (fr < 0)
		return (res - 1);
	else
		return (res);
}
