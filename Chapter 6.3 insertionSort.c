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