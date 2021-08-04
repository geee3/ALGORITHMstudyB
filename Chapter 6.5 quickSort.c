/*
by GEEE3, August 4, 2021
Quicksort is a divide-and-conquer algorithm
It works by selecting a 'pivot' element from the array and partitioning the other elements
into two sub-arrays, according to whether they are less than or greater than the pivot
The sub-arrays are then sorted recursively
This can be done in-place, requiring small additional amounts of memory to perform the sorting

Mathematical analysis of quicksort shows that,
on average, the algorithm takes O(nlog n) comparisons to sort n items
In worst case, it makes O(n^2) comparisons
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)

void quickSort(int arr[], int first, int last) {
    int i, j, pivot, temp;

    if(first < last){
        pivot = first;
        i = first;
        j = last;

        while(i < j){
            while(arr[i] <= arr[pivot] && i < last)
                i++;
            while(arr[j] > arr[pivot])
                j--;
            if(i < j)
                swap(int, arr[i], arr[j]);
        }
        swap(int, arr[pivot], arr[j]);
        quickSort(arr, first, j-1);
        quickSort(arr, j+1, last);
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

    quickSort(arr, 0, size - 1);
    printf("quick sorted : ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}