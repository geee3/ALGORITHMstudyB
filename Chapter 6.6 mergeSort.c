/*
by GEEE3, August 5, 2021
Merge sort is an efficient, general-purpose, and comparison-based sorting algorithm
In sorting n objects, merge sort has an average and worst-case performance of O(nlog n)
If the running time of merge sort for a list of length n is T(n),
then the recurrence relation T(n) = 2T(n/2) + n follows from the definition of the algorithm

Conceptually, a merge sort works as follows:
1. Divide the unsorted list into n sublists, each containing one element
2. Repeatedly merge sublists to produce new sorted sublists until there is only one remaining
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, size - 1);
    printf("merge sorted : ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}