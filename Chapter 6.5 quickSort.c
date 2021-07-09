/*
by GEEE3, July 8, 2021
Quick sort is an in-place sorting algorithm and also divide-and-conquer algorithm
It works by selecting a 'pivot' element from the array and partitioning the other elements into sub-arrays
according to whether they are less than or greater than the pivot
The sub-arrays are then sorted recursively
This can be done in-place, requiring small additional amounts of memory to perform the sorting

Mathematical analysis of quicksort shows, on average, the algorithm takes O(nlog n) comparisons to sort
In the worst case, it makes O(n^2) comparisons, though this behavior is rare
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void quickSort(int arr[], int left, int right) {
    int pl = left;
    int pr = right;
    int pivot = arr[(pl + pr) / 2];

    do {
        while(arr[pl] < pivot) pl++;
        while(arr[pr] > pivot) pr--;
        if(pl <= pr) {
            swap(int, arr[pl], arr[pr]);
            pl++;
            pr--;
        }
    } while(pl <= pr);
    if(left < pr) quickSort(arr, left, pr);
    if(pl < right) quickSort(arr, pl, right);
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

    quickSort(arr, 0, size);
    printf("quick sorted : ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}