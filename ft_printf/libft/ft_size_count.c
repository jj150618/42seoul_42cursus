

#include "libft.h"

size_t	ft_size_count(long long lln)
{
	size_t	count;

	count = 1;
	if (lln < 0)
	{
		count = 2;
		lln = -lln;
	}
	while (lln >= 10)
	{
		count++;
		lln /= 10;
	}
	return (count);
}
