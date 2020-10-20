#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
	char Love[10] = {"ILOVEYOU"};
	char Love_1[10] = {"IHATEYOU"};

	printf("\n\n\n");
	int i;
	int j;
	
	i = ft_strlen(Love);
	j = ft_strlcat(Love, Love_1, 10);
	printf("%d\n%d\n\n\n",i, j);

	printf("%d", ft_strncmp("test\200", "test\0", 6));
	printf("%d", strncmp("test\200", "test\0", 6));
	return (0);
}
