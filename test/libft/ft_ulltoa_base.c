

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long n, unsigned int base)
{
	size_t		size;
	size_t		end;
	char		*res;

	end = 0;
	size = ft_size_count_base(n, base);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	res[size] = '\0';
	while (size > 0 && --size >= end)
	{
		res[size] = "0123456789abcdef"[n % base];
		n /= base;
	}
	return (res);
}
