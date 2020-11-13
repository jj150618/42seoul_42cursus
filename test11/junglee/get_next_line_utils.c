/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:21:19 by junghlee          #+#    #+#             */
/*   Updated: 2020/10/29 09:40:34 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** STRCHR(3)
**
** NAME
** strchr, strrchr -- locate character in string
**
** LIBRARY
** Standard C Library (libc, -lc)
**
** SYNOPSIS
** #include <string.h>
**
** char	*strchr(const char *s, int c);
**
** char	*trrchr(const char *s, int c);
**
** DESCRIPTION
** The strchr() function locates the first occurrence of c
** (converted to a char) in the string pointed to by s.
** The terminating null character is considered to be part of the string;
** therefore if c is `\0', the functions locate the terminating `\0'.
**
** The strrchr() function is identical to strchr(), except it locates the
** last occurrence of c.
**
** RETURN VALUES
** The functions strchr() and strrchr() return a pointer to the located
** character, or NULL if the character does not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (*p == c ? p : 0);
}

/*
** STRDUP(3)
**
** NAME
** strdup, strndup -- save a copy of a string
**
** SYNOPSIS
** #include <string.h>
**
** char	*strdup(const char *s1);
**
** char	*strndup(const char *s1, size_t n);
**
** DESCRIPTION
** The strdup() function allocates sufficient memory for a copy of the string
** s1, does the copy, and returns a pointer to it.
** The pointer may subsequently be used as an argument to the function free(3).
**
** If insufficient memory is available, NULL is returned and errno is set to
** ENOMEM.
**
** The strndup() function copies at most n characters from the string s1 always
** NUL terminating the copied string.
*/

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;

	if (!(dup = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	ft_memcpy(dup, s1, n);
	*(dup + n) = '\0';
	return (dup);
}

/*
** MEMCPY(3)
**
** NAME
** memcpy -- copy memory area
**
** SYNOPSIS
** #include <string.h>
**
** void	*memcpy(void *restrict dst, const void *restrict src, size_t n);
**
** DESCRIPTION
** The memcpy() function copies n bytes from memory area src to memory area
** dst.  If dst and src overlap, behavior is undefined.  Applications in
** which dst and src might overlap should use memmove(3) instead.
**
** RETURN VALUES
** The memcpy() function returns the original value of dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;
	size_t			i;

	if (!dst && !src)
		return (0);
	u_dst = (unsigned char *)dst;
	u_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(u_dst + i) = *(u_src + i);
		i++;
	}
	return (dst);
}

/*
** Function name
** ft_strjoin
**
** Prototype
** char	*ft_strjoin(char const *s1, char const *s2);
**
** Turn in files
** -
**
** Parameters
** #1. The prefix string.
** #2. The suffix string.
**
** Return value
** The new string. NULL if the allocation fails.
**
** External functs.
** malloc
**
** Description
** Allocates (with malloc(3)) and returns a new string, which is the result
** of the concatenation of 's1' and 's2'.
*/

char	*gnl_join(char const *s1, size_t s1_len, char const *s2, size_t s2_len)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_memcpy(s, s1, s1_len);
	ft_memcpy(s + s1_len, s2, s2_len);
	*(s + s1_len + s2_len) = '\0';
	return (s);
}
