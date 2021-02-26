

#include "libft.h"

double	ft_round(double num, int digit)
{
	return (ft_floor(num * ft_pow(10, digit) + 0.5) / ft_pow(10, digit));
}
