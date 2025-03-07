// wap to perform all arithmetic ops using pointer

#include <stdio.h>
#include "bootstrap.c"


void main()
{
    int *a, *b,a1,b1;
    printf("Enter the value of a: ");
    scanf("%d",&a1);
    printf("Enter the value of b: ");
    scanf("%d",&b1);
    a=&a1;
    b=&b1;
    printf("Sum=%d\n",*a+*b);
    printf("Difference=%d\n",*a-*b);
    printf("Product=%d\n",*a**b);
    printf("Division=%d\n",*a/ *b);
}