mmmmmmmmmmmmmmmmmmm

#include "libft.h"

size_t	ft_size_ucount(unsigned long long lln)
{
	size_t	count;

	count = 1;
	while (lln >= 10)
	{
		count++;
		lln /= 10;
	}
	return (count);
}
