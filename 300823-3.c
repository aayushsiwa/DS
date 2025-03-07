// wap to display a given sparse matrix in a 3-tuple array
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
    printf("The sparse matrix in a 3-tuple array is:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                printf("%d\t%d\t%d\n", i, j, a[i][j]);
                k++;
            }
        }
    }
    printf("The number of non-zero elements in the sparse matrix is: %d\n", k);
}