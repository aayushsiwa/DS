#include<stdio.h>
#include<stdlib.h>

struct data{
    int number;
};


int main(){
    int a=10;
    int *p=&a;
    struct data *d=(struct data *)malloc(sizeof(struct data));
    d->number=10;
    // printf("%d",d->number);
    
}