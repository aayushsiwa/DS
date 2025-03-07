// Quick Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Partition the array into two parts, left and right
 * left contains all the elements less than pivot
 * right contains all the elements greater than pivot
 * pivot is the last element of the array
 */

int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[right], &arr[i + 1]);
    return i + 1;
}

void quickSort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %lf\n", (double) (end - start) / CLOCKS_PER_SEC);
    return 0;
}

/*
 * Sample I/O:
 * Enter the number of elements: 5
 * Enter the elements: 5 4 3 2 1
 * Sorted array: 1 2 3 4 5
 * Time taken: 0.000001
 *
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 */