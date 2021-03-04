#include<stdio.h>

int main()
{
    char *a;
    char b = 30;

    a = &b;
    printf("%d    %p\n",a, a);
}
