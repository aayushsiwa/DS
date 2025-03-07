// wap to sort the rows of matrix in ascending order followed by sorting the columns in descending order.

#include <stdio.h>
#include <stdlib.h>

int print_mat(int mat[20][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    printf("Enter the size of matrix: ");
    int n;
    scanf("%d", &n);
    int arr[20][20];
    printf("Enter the elements of matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The matrix is: \n");
    print_mat(arr, n);
    printf("The matrix after sorted in ascending order row wise : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (arr[i][j] < arr[i][k])
                {
                    int temp = arr[i][j];
                    arr[i][j] = arr[i][k];
                    arr[i][k] = temp;
                }
            }
        }
    }
    print_mat(arr, n);
    printf("The matrix after sorted in descending order column wise : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (arr[i][j] > arr[k][j])
                {
                    int temp = arr[i][j];
                    arr[i][j] = arr[k][j];
                    arr[k][j] = temp;
                }
            }
        }
    }
    print_mat(arr, n);
}