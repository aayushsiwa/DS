// wap to find k numbers having the maximum frequency in the given array i.e the top k numbers having the maximum
// frequency. If two numbers have the same frequency then the larger number should be given preference. The numbers
// should be displayed in the decreasing order of their frequency. If two numbers have the same frequency then the
// smaller number should be displayed first.

#include <stdio.h>

int array_input(int a[], int n)
{
    printf("Enter the elements:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element at %d- ", i);
        scanf("%d", &a[i]);
    }
}

int print_array(int a[], int n)
{
    printf("\nArray is:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ,", a[i]);
    }
}

void main()
{
    int n = 20;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    array_input(a, n);
    // int a[]={1,2,3,4,5,6,7,8,9,4,1,2,3,4,5,1,2,3,1,2};
    // printf("%d",sizeof(a)/sizeof(int));
    print_array(a, n);
    int k = 0;
    while (k < 1 || k > n)
    {
        printf("\nEnter the value of k: ");
        scanf("%d", &k);
        if (k < 1 || k > n)
        {
            printf("Invalid input.\n");
        }
    }
    int distinct[k];
    int count[k];
    for (int i = 0; i < k; i++)
    {
        distinct[i] = 0;
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < k)
        {
            if (a[i] == distinct[j])
            {
                count[j]++;
                break;
            }
            else if (distinct[j] == 0)
            {
                distinct[j] = a[i];
                count[j]++;
                break;
            }
            j++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k - i - 1; j++)
        {
            if (count[j] < count[j + 1])
            {
                int temp = count[j];
                count[j] = count[j + 1];
                count[j + 1] = temp;
                temp = distinct[j];
                distinct[j] = distinct[j + 1];
                distinct[j + 1] = temp;
            }
        }
    }
    // print_array(distinct,k);
    // print_array(count,k);
    printf("\nThe top %d numbers having the maximum frequency are: ", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", distinct[i]);
    }
    printf("\n");
}