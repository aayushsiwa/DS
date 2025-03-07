// wap to create a 1d array of n elements following menu based operations using a insert
// a given element at specific pos
// b delete an element from specific position
// c linear search to search an element
// d traversal of array

#include <stdio.h>
#include <stdlib.h>
#include "bootstrap.c"

int insert_element(int arr[], int n)
{
    int pos, ele, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter element: ");
    scanf("%d", &ele);
    if (pos < 0)
    {
        printf("Invalid position");
    }
    else
    {
        for (i = n - 1; i >= pos; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos] = ele;
        n++;
    }
    printf("\n---------------xxx---------------\n");
}

int delete_element(int arr[], int n)
{
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > n)
    {
        printf("Invalid position");
    }
    else
    {
        for (i = pos; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;
    }
    printf("\n---------------xxx---------------\n");
}

int search(int arr[], int n)
{
    int ele, i;
    printf("Search for- ");
    scanf("%d", &ele);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            printf("Element found at %d", i);
        }
        else
        {
            printf("Element not found.");
        }
    }
    printf("\n---------------xxx---------------\n");
}

int main()
{
    int n, i, pos, ele, choice, arr[50];
    printf("Array Size? ");
    scanf("%d", &n);
    array_input(arr,n);
    while (1)
    {
        printf("\n1->Insert an element at specific position");
        printf("\n2->Delete element at specific position");
        printf("\n3->Linear search");
        printf("\n4->Traversal of array");
        printf("\n5->Exit");
        printf("\nEnter choice- ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            insert_element(arr, n);
            break;
        case 2:
            delete_element(arr, n);
            break;
        case 3:
            search(arr, n);
            break;
        case 4:
            print_array(arr, n);
            printf("\n---------------xxx---------------\n");
            break;
        case 5:
            return 0;
        }
    }
}