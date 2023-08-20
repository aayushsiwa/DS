// wap to find the largest element and its position in an array.

#include<stdio.h>
#include "bootstrap.c"

void main(){
    int a[50],n;
    printf("Array Size? ");
    scanf("%d",&n);
    array_input(a,n);
    int* arr=max_array(a,n);
    printf("Largest number is %d at %d",arr[0],arr[1]);
    free(arr);
}