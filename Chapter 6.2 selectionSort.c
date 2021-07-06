/*
by GEEE3, July 6, 2021
In computer science, selection sort is an in-place comparison sorting algorithm
It has an O(n^2) time complexity, which makes it inefficient on large lists,
and generally performs worse than the similar insertion sort

The algorithm divides the input list into two parts:
a sorted sublist of items which is built up form left to right at the front(left) of the list,
and a sublist of the remaining unsorted items that occupy the rest of the list
Initially, the sorted sublist is empty and the unsorted sublist is the entire input list
The algorithm proceeds by finding the smallest(or largest) element in the unsorted sublist,
exchanging it with the leftmost unsorted element, and moving the sublist boundaries one element to the right
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)

void selectionSort(int arr[], int size) {
    int i, j = 0;
    int min, pointer;

    for(i = 0; i < size - 1; i++) {
        min = arr[j];
        for(j = i; j < size; j++) {
            if(min > arr[j]) {
                min = arr[j];
                pointer = j;
            }
        }
        swap(int, arr[i], arr[pointer]);
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

    selectionSort(arr, size);
    printf("selection sorted : ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}