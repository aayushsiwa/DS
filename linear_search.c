// wap to write linear search program for array of integers

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arr = NULL;
    int size = 0, i = 0, num = 0, flag = 0;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    arr = (int *)malloc(sizeof(int) * size);

    printf("Enter the elements of array: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to be searched: ");
    scanf("%d", &num);

    for(i = 0; i < size; i++)
    {
        if(arr[i] == num)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        printf("Number found at index %d\n", i);
    }
    else
    {
        printf("Number not found\n");
    }

    return 0;
}