// wap to make a bootstrap file that contains all important functions that may be reuired in future

#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

int array_input(int a[], int n)
{
    printf("Enter the elements:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element at %d- ", i);
        scanf("%d", &a[i]);
    }
}

int *max_array(int a[], int n)
{
    int *out = (int *)malloc(2 * sizeof(int));
    int i, max = 0, pos;
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            pos = i;
        }
        else
        {
            continue;
        }
    }
    out[0] = max;
    out[1] = pos;
    return out;
    // printf("Largest element is %d at %d", max, pos);
}

int print_array(int a[], int n)
{
    printf("\nArray is:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ,", a[i]);
    }
}

int swap_elements(int a[], int n)
{
    int i = 0, s;
    for (i = 0; i < n; i++)
    {
        s = a[i];
        a[i] = a[n - (i + 1)];
        a[n - (i + 1)] = s;
    }
    printf("\nArray after element swap:-\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ,", a[i]);
    }
}

int sum_array(int a[], int n)
{
    int sum = 0, i;
    for (i = 0; i < n; i++)
    {
        sum += a[i];
        // printf("%d",a[i]);
    }
    return sum;
}

int factorial(int i)
{
    int f = 1;
    for (i == i; i > 0; i--)
    {
        f = f * i;
    }
    return f;
}

int is_armstrong(int a)
{
    int b, d = a, sum = 0;
    while (a > 0)
    {
        b = a % 10;
        a = a / 10;
        sum += b * b * b;
    }
    if (sum == d)
    {
        printf("The given number is an Angstrom number\n");
    }
    else
    {
        printf("The given number is not an Angstrom number\n");
    }
}

int is_perfect(int a)
{
    int i, s = 0;
    for (i = 1; i < a; i++)
    {
        if (a % i == 0)
        {
            s = s + i;
        }
    }
    if (s == a)
    {
        printf("Perfect");
    }
    else
        printf("Not Perfect");
}

int sum(int a, int b)
{
    return a + b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}
int difference(int a, int b)
{
    return a - b;
}

int pointer_array_input_output(int *a, int n, char c)
{
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element:", i);
        scanf("%d", a + i);
    }
    if (c == 'p')
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d element is %d\n", i, *(a + i));
        }
    }
}