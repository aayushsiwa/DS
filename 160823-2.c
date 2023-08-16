// wap to find the largest element and its position in an array.

#include<stdio.h>

int array_input(int a[],int n){
    printf("Enter the elements:-\n");
    for(int i=0;i<n;i++){
        printf("%i element- ",i+1);
        scanf("%d",&a[i]);
    }
}

int max_array(int a[],int n){
    int i,max=0,pos;
    for(i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
            pos=i;
        }else{
            continue;
        }
    }
    printf("Largest element is %d at %d",max,pos);
}

void main(){
    int a[50],i,n,max=0,maxi;
    printf("Array Size? ");
    scanf("%d",&n);
    array_input(a,n);
    max_array(a,n);
}