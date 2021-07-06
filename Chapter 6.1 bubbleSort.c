/*
by GEEE3, July 6, 2021
Bubble sort is a simple sorting algorithm that repeatedly steps through the list,
compares adjacent elements and swaps them if they are in the wrong order
The pass through the list is repeated until the list is sorted

Bubble sort has a worst-case and average complexity of O(n^2), where n is the number of items
Most practical sorting algorithms have substantially better worst-case or average complexity, often O(nlog n).
Even other O(n^2) sorting algorithms, generally run faster than bubble sort, and are no more complex
Therefore, bubble sort is not a practical sorting algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)

void bubbleSort(int arr[], int size) {
    int i, j;
    
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - 1; j++) {
            if(arr[j] > arr[j + 1])
                swap(int, arr[j], arr[j + 1]);
        }
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

    bubbleSort(arr, size);
    printf("bubble sorted : ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}