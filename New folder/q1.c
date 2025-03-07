// Q1.Given an array of integers. Write a program to find the K-th largest sum of
// contiguous subarray within the array of numbers which has negative and positive
// numbers.

#include <stdio.h>
#include <stdlib.h>

int array_input(int a[], int n)
{
    printf("Enter the elements:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element at %d- ", i);
        scanf("%d", &a[i]);
    }
}

int KLargestSum(int arr[], int n, int k)
{
    int *prefixSum = (int *)malloc((n + 1) * sizeof(int));
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }
    int *subSum = (int *)malloc((n * (n + 1) / 2) * sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            subSum[count++] = prefixSum[j] - prefixSum[i];
        }
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (subSum[j] < subSum[j + 1])
            {
                int temp = subSum[j];
                subSum[j] = subSum[j + 1];
                subSum[j + 1] = temp;
            }
        }
    }
    int result = subSum[k - 1];
    free(prefixSum);
    free(subSum);
    return result;
}

int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    array_input(arr, n);
    int k;
    printf("Enter the value of K: ");
    scanf("%d", &k);
    int result = KLargestSum(arr, n, k);
    printf("The %d-th largest sum of contiguous subarray is: %d\n", k, result);
    return 0;
}
