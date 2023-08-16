// wap to find the sum of the numbers present in an array.

#include<stdio.h>

int array_input(int a[],int n){
    printf("Enter the elements:-\n");
    for(int i=0;i<n;i++){
        printf("%i element- ",i+1);
        scanf("%d",&a[i]);
    }
}

int sum_array(int a[],int n){
    int sum=0,i;
    for(i=0;i<n;i++){
        sum+=a[i];
        // printf("%d",a[i]);
    }
    return sum;
}

void main() {
    int a[50],i,sum,n;
    printf("Array Size?");
    scanf("%d",&n);
    array_input(a,n);
    printf("sum of the elements in the array is: %d",sum_array(a,n));
}