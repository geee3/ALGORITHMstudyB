/*
by GEEE3, July 23, 2021
Insertion sort iterates, consuming one input element each repetition, and grows a sorted list
At each iteration, insertion sort removes one element from the input data,
finds the location it belongs within the sorted list, and inserts it there
It repeats until no input elements reamin

Sorting is typically done in-place, by iterating up the array, growing the sorted list behind it
At each array-position, it checks the value there against the largest value in the sorted list
If larger, it leaves the element in the place and moves to the next
If smaller, it finds the correct position within the sorted list,
shifts all the larger values up to make a space, and inserts into that correct position

The best case input is an array that is already sorted
In this case insertion sort has a linear running time, O(n)
The simplest worst case input is an array sorted in reverse order
This gives insertion sort a quadratic running time, O(n^2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int size) {
    int i, j, k;
    int location, insertion, maxFlag;
    
    for(i = 1; i < size; i++) {
        maxFlag = 0;
        insertion = arr[i];
        for(j = 0; j < i; j++) {
            if(arr[i] <= arr[j]) {
                location = j;
                maxFlag = 1;
                break;
            }
        }
        if(maxFlag == 0)
            location = i;
        for(k = i; k > location; k--) {
            arr[k] = arr[k - 1];
        }
        arr[location] = insertion;
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

    insertionSort(arr, size);
    printf("insertion sorted : ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}