
#include<stdio.h>
// #include "bootstrap.c"

// wap to 4. Write an recursive algorithm to sum the list of numbers
// int psum(int n,int sum){
//     if(n>0){
//         // printf("%d\n", n);
//         sum+=n;
//         n--;
//         return psum(n,sum);
//     }
//     else return sum;
// }

// void main(){
//     int n=20;
//     int sum=0;
//     printf("%d",psum(n,sum));
// }



// wap to write a recursive algo to print smallest integer in an array
// int smallest(int arr[], int n, int i, int small){
//     if(i<n){
//         if(arr[i]<small){
//             small = arr[i];
//         }
//         i++;
//         return smallest(arr, n, i, small);
//     }
//     else return small;
// }
// void main(){
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int i=0;
//     int small = arr[0];
//     printf("%d", smallest(arr, n, i, small));
// }


// wap to write an recursive algorithm to print from 1 to n (where n > 1)
// void print(int n){
//     if(n<=20){
//     printf("%d\n", n);
//     n++;
//     print(n);
//     }
//     else return;
// }

// void main(){
//     int n=1;
//     print(n);
// }