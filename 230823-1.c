// wap to find sum of 1!/1 + 2!/2 + ... + 5!/5

#include <stdio.h>
#include "bootstrap.c"

void main()
{
    int i, numerator,denominator, n,sum=0;
    printf("Enter number of terms:- ");
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
    {
        numerator = factorial(i);
        denominator=i;
        sum+=(numerator/denominator);
    }
    printf("%d", sum);
}