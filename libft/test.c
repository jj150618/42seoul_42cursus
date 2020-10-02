#include <stdio.h>
#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n);

int main()
{
	char str1[] = "\0";
	char str2[40];
	char str4[40];
	char str3[40];
	char *a;
	char *b;


	a = memcpy(str2, str1, strlen(str1) + 1);
	b = ft_memcpy(str4, str1, strlen(str1) + 1);

			    printf("str1: %s\nstr2: %s\nstr4: %s\n", str1, str2, str4);
	printf("%s, %s\n", a, b);
				  return 0;
}
