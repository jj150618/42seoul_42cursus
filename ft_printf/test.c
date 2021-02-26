#include <stdio.h>
#include <unistd.h>

int main()
{
	int a;
	int b;
	a = 123456;
	b = printf("a% abbcc%d",a);
	printf("\n%d\n", b);
	b = write(1, "abc", 1);
	printf("\n%     d\n", b);
	printf("%");
}
