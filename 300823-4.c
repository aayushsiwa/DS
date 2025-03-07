// wap to perform transpose of a given sparse matrix.
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, m, i, j, k = 0;
    printf("Enter the size of the sparse matrix: ");
    scanf("%d %d", &n, &m);
    int a[n][m];
    printf("Enter the elements of the sparse matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                k++;
            }
        }
    }
    int transpose[k][3];
    k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                transpose[k][0] = j;
                transpose[k][1] = i;
                transpose[k][2] = a[i][j];
                k++;
            }
        }
    }
    printf("The sparse matrix in a 3-tuple array is:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                printf("%d\t%d\t%d\n", i, j, a[i][j]);
                // k++;
            }
        }
    }
    printf("The transpose of the sparse matrix is:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i < k; i++)
    {
        printf("%d\t%d\t%d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }
}