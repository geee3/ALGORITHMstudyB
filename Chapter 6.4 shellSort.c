/*
by GEEE3, July 23, 2021
Shellsort is a highly efficient sorting algorithm and is based on insertion sort algorithm
This algorithm can be seen as either a generalization of sorting by exchange or sorting by insertion
It avoids large shifts as in case of insertion sort,
if the smaller value is to the far right and has to be moved to the far left
By using insertion sort on widely spread elements,
first to sort them and then sorts the less widely spaced elements, which termed as interval
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

void shellSort(int arr[], int size) {
    int i, j, gap, pointer, escapeFlag, endFlag = 0;
    int *shell;
    
    gap = size / 2;
    if(gap % 2 == 0)
        gap += 1;
    shell = (int *)malloc(sizeof(int) * size);

    while(endFlag == 0) {
        escapeFlag = 0;
        pointer = 0;
        
        while(escapeFlag == 0) {
            for(i = 0; i < size; i++)
                shell[i] = 0;
            j = 0;

            for(i = pointer; i < size; i += gap)
                shell[j++] = arr[i];
            insertionSort(shell, j);
            j = 0;

            for(i = pointer; i < size; i += gap)
                arr[i] = shell[j++];
            pointer += 1;
            if(pointer == gap)
                escapeFlag = 1;
        }
        if(gap == 1)
            endFlag = 1;
        gap = gap / 2;
        if(gap % 2 == 0)
            gap += 1;
    }
    free(shell);
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

    shellSort(arr, size);
    printf("shell sorted : ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}