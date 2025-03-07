// wap to a matrix mat[][], we have to check if the sum of i-th row is equal to the sum
// of i-th column or not.

#include <stdio.h>

void print_mat(int mat[20][20], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int mat[20][20], x=-1;
    printf("enter the size of matrix- ");
    int n;
    scanf("%d", &n);
    printf("enter the elements of matrix:-\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("this is the matrix:-\n");
    print_mat(mat,n);
    while(x<0 || x>n){
        printf("\nEnter the i-th row / column: ");
        scanf("%d",&x);
        if(x<0 || x>n){
            printf("Invalid input.\n");
        }
    }
    printf("Row: ");
    for(int i=0;i<n;i++){
        printf("%d ",mat[x][i]);
    }
    printf("\nColumn: ");
    for(int i=0;i<n;i++){
        printf("%d ",mat[i][x]);
    }
    int sum_row = 0, sum_col = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum_row += mat[x][j];
            sum_col += mat[i][x];
        }
    }
    if(sum_col==sum_row){
        printf("\ncheck ok");
    }
    else{
        printf("\nnot ok");
    }
}