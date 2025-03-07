// wap to write binary search program for array of integers
#include<stdio.h>
int main()
{
    int a[10],i,n,search,first,last,middle;
    printf("enter the number of elements in array\n");
    scanf("%d",&n);
    printf("enter %d integers\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the value to find\n");
    scanf("%d",&search);
    first=0;
    last=n-1;
    middle=(first+last)/2;
    while(first<=last)
    {
        if(a[middle]<search)
        {
            first=middle+1;
        }
        else if(a[middle]==search)
        {
            printf("%d found at location %d\n",search,middle+1);
            break;
        }
        else
        {
            last=middle-1;
        }
        middle=(first+last)/2;
    }
    if(first>last)
    {
        printf("not found %d is not present in the list\n",search);
    }
    return 0;
}