// Selective Sort algorithm
// Selection (A,n)
// 1. for i = 1 to n-1
// 2.   min = i
// 3.   for j = i+1 to n
// 4.     if A[j] < A[min]
// 5.       min = j
// 6.   temp = A[i]
// // 7.   A[i] = A[min]
// // 8.   A[min] = temp
// // 9. return A
// The selection sort algorithm is similar to the insertion sort algorithm in that it divides the input list into two parts: 
// the sublist of items already sorted and the sublist of items remaining to be sorted. 
// The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, 
// exchanging it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right.