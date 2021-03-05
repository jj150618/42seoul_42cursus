
#include "ft_printf.h"

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

char	*ft_ulltoa(unsigned long long n)
{
	size_t		size;
	size_t		end;
	char		*res;

	end = 0;
	size = ft_size_ucount(n);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	res[size] = '\0';
	while (size > 0 && --size >= end)
	{
		res[size] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

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