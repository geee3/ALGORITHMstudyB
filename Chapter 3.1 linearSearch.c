/*
by GEEE3, February 27, 2021
Linear Search or Sequential Search is a method for finding an element within a list
It sequentially checks each element of the list until a match is found or the whole list has been searched
A linear search runs in at worst linear time and makes at most n comparisons, where n is the length of the list
If each element is equally likely to be searched, them lisear search has an average case of (n + 1) / 2 comparisons,
but the average case can be affected if the search probabilities for each element vary
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* na개의 요소를 가진 배열에서 key와 일치하는 요소를 선형검색 */
int linearSearch (int ary[], int na, int key) {
    int i;
    for (i = 0; i < na; i++) {
        if (ary[i] == key)
            return i;
    }
    return -1;
}

int main (void) {
    int key, result, na, i;
    int *ary;
    
    printf("size of array : ");
    scanf("%d", &na);
    ary = (int *)malloc(sizeof(int) * na);
    
    printf("array : ");
    srand(time(NULL));
    for (i = 0; i < na; i++) {
        ary[i] = rand() % 100;
        printf("%d ", ary[i]);
    }
    printf("\n");

    printf("Enter the Key value to search : ");
    scanf("%d", &key);
    result = linearSearch(ary, na, key);

    switch(result + 1) {
        case 0:
            printf("There is no key value in the array.\n");
            break;
        case 1:
            printf("%d is the first value of the array.\n", key);
            break;
        case 2:
            printf("%d is the second value of the array.\n", key);
            break;
        case 3:
            printf("%d is the third value of the array.\n", key);
            break;
        default:
            printf("%d is the %dth value of the array.\n", key, result + 1);
            break;
    }
    free(ary);
    return 0;
}