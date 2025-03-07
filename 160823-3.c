// wap to swap the elements present in an array(1st to last).

#include<stdio.h>

int array_input(int a[],int n){
    printf("Enter the elements:-\n");
    for(int i=0;i<n;i++){
        printf("%i element- ",i+1);
        scanf("%d",&a[i]);
    }
}

int print_array(int a[],int n){
    printf("\nArray is:-\n");
    for(int i=0;i<n;i++){
        printf("%d ,",a[i]);
    }
}

int swap_elements(int a[],int n){
    int i=0,s;
    for(i=0;i<n/2;i++){
        s=a[i];
        a[i]=a[n-(i+1)];
        a[n-(i+1)]=s;
    }
    printf("\nArray after element swap:-\n");
    for(i=0;i<n;i++){
        printf("%d ,",a[i]);
    }
}

void main(){
    int a[50],i,n,s;
    printf("Array Size? ");
    scanf("%d",&n);
    array_input(a,n);
    // printf("%d",a[n-1]);
    print_array(a,n);
    swap_elements(a,n);   
}