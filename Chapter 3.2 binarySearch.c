/*
by GEEE3, February 27, 2021
Binary search begins by comparing an element in the middle of the sorted array with the target value
If the target value matches the element, its position in the array is returned
if the target value is less than the element, the search continues in the lower half of the array
If the target value is greater than the element, the search continues in the upper half of the array
By doing this, the algorithm eliminates the half in which the target value cannot lie in each iteration
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* na개의 요소를 가진 배열에서 key와 일치하는 요소를 이진검색 */
int binarySearch(int ary[], int l, int r, int x) { 
	if (r >= l) { 
		int mid = l + (r - l) / 2; 
		if (ary[mid] == x) {
			return mid;
        }
        else if (ary[mid] > x) {
			return binarySearch(ary, l, mid - 1, x);
        }
		else {
            return binarySearch(ary, mid + 1, r, x);
        }
	}
	return -1; 
}

/* na개의 요소를 가진 배열을 오름차순 정렬 */
void selectionSort (int ary[], int na) {
    int i, j, counter, temp, min;

    for (i = 0; i < na; i++) {
        min = ary[i];
        for (j = i; j < na; j++) {
            if (ary[j] <= min) {
                counter = j;
                min = ary[j];
            }
        }
        temp = ary[i];
        ary[i] = ary[counter];
        ary[counter] = temp;
    }
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

    selectionSort(ary, na);
    printf("sorted array : ");
    for (i = 0; i < na; i++) {
        printf("%d ", ary[i]);
    }
    printf("\n");

    printf("Enter the Key value to search : ");
    scanf("%d", &key);
    result = binarySearch(ary, 0, na - 1, key);

    switch(result + 1) {
        case 0:
            printf("There is no key value in the array.\n");
            break;
        case 1:
            printf("%d is the first value of the sorted array.\n", key);
            break;
        case 2:
            printf("%d is the second value of the sorted array.\n", key);
            break;
        case 3:
            printf("%d is the third value of the sorted array.\n", key);
            break;
        default:
            printf("%d is the %dth value of the array.\n", key, result + 1);
            break;
    }
    free(ary);
    return 0;
}