// wap to make a bootstrap file that contains all important functions that may be reuired in future

#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

int array_input(int a[], int n)
{
    printf("Enter the elements:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d- ", i + 1);
        scanf("%d", &a[i]);
    }
}

int* max_array(int a[], int n)
{
    int* out = (int*)malloc(2 * sizeof(int));
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
    out[0]=max;
    out[1]=pos;
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