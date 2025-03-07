// Heap Sort
// Heap is a special tree-based data structure in which the tree is a complete binary tree.
// A binary tree is said to be a heap data structure if:
// 1. It is a complete binary tree.
// 2. All nodes in the tree follow the property that they are greater than their children i.e. the largest element is at the root and 
// both its children and smaller than the root and so on.
// Make a complete binary tree from the given array and then convert it into a heap.
// Then, swap the first and last element of the array and heapify the array from the root to the last element.
// Repeat this process until the array is sorted.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Heapify the subtree rooted at index i
 * n is the size of the heap
 */

void heapify(int *arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
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
    heapSort(arr, n);
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
 * Space Complexity: O(1)
 * Stable: No
 * In-Place: Yes
 * 
 * Note: Heap sort is not stable.
 * 
 * Heap sort is an in-place sorting algorithm but is not a stable sort.
 * 
 * Heap sort is not a stable sort because the heapify process can change the
 * relative order of equal elements.
 * 
 * Heap sort is an in-place sorting algorithm but is not a stable sort.
 * 
 * Heap sort is not a stable sort because the heapify process can change the
 * relative order of equal elements.
 * 
 * Heap sort is an in-place sorting algorithm but is not a stable sort.
 * 
 * Heap sort is not a stable sort because the heapify process can change the
 * relative order of equal elements.
 * 
 * Heap sort is an in-place sorting algorithm but is not a stable sort.
 * 
 * Heap sort is not a stable sort because the heapify process can change the
 * relative order of equal elements.
 * 
 * Heap sort is an in-place sorting algorithm but is not a stable sort.
 * 
 * Heap sort is not a stable sort because the heapify process can change the
 * relative order of equal elements.
 * 
 * Heap sort is an in-place sorting algorithm but is not a stable sort.
 * 
 * Heap sort is not a stable sort because the heapify process can change the
 * relative order of equal elements.
 * 
 * Heap sort is an in-place sorting algorithm but is not a stable sort.
 * 
 * Heap sort is not a stable sort because the heapify process can change the
 * relative order of equal elements.
 * 
 * Heap sort is an in-place sorting algorithm but is not a stable sort.
 * 
 * Heap sort is not a stable sort because the heapify process can change the
 * relative order of equal elements.
 * 
 * Heap sort is an in-place sorting algorithm but is not a stable sort.
 * 
 * Heap sort is not a stable sort because the heapify process can change the
 * relative order of equal elements.
 * 
 * Heap sort is an in-place sorting algorithm but is not a stable sort.
*/