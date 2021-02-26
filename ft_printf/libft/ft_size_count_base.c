

#include "libft.h"

size_t	ft_size_count_base(unsigned long long lln, unsigned int base)
{
	size_t	count;

	count = 1;
	while (lln >= base)
	{
		count++;
		lln /= base;
	}
	return (count);
}
