/*
by GEEE3, August 10, 2021
The heap sort algorithm can be divided into two parts

In the first step, a heap is built out of the data
The heap is often placed in an array with the layout of a complete binary tree
For a zero-based array, the root node is stored at index 0;
if 'i' is the index of the current node, then
iParent(i) = (i - 1) / 2
iLeftChild(i) = 2 * i + 1
iRightChild(i) = 2 * i + 2

In the second step, sorted array is created by repeatedly removing largest element from heap
(the root of the heap), and inserting it into the array
The heap is updated after each removal to maintain the heap property
Once all objects have been removed from the heap, the result is a sorted array
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[largest])
        largest = left;
    if(right < size && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(int, arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    //Build max heap
    for(int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    //Heap sort
    for(int i = size - 1; i >= 0; i--) {
        swap(int, arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(void) {
    int i, size;
    int *arr;
    printf("size of array : ");
    scanf("%d", &size);
    arr = (int *)malloc(sizeof(int) * size);
    
    printf("array : ");
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, size);
    printf("heap sorted : ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}