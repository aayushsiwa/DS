// wap to store n elements in an array using dynamic memory allocation and display result using pointer
#include <stdio.h>
#include <stdlib.h>
#include "bootstrap.c"

int main()
{
    int n, i;
    int *a;
    printf("Enter the size of array:");
    scanf("%d", &n);
    pointer_array_input_output(a, n, 'p');
}