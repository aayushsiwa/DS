// wap to perform following op on square matrix using functions
// find no of non zero elements.
// display upper triangular matrix
// display elements just above and below the main diagonal

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, j, count = 0;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                count++;
            }
        }
    }
    printf("\nThe number of non-zero elements in the matrix is: %d\n\n", count);
    printf("The upper triangular matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i <= j)
            {
                printf("%d  ", a[i][j]);
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("The elements just above and below the main diagonal are:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(n == 2)
            {
                if (i != j)
                {
                    printf("%d ", a[i][j]);
                }
            }
            else{
                if (i != j && (i + n - 1) != j && i != (j + n - 1))
                {
                    printf("%d ", a[i][j]);
                }
            }
        }
    }
}