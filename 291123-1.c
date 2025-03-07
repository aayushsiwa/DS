// WAP to sort array of elements in ascending and descending order by insertion sort using function
#include<stdio.h>
void insertion_sort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;	
    }
}

void main()
{
    int a[100],n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the elements of array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertion_sort(a,n);
    printf("The sorted array in ascending order is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nThe sorted array in descending order is: ");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
}