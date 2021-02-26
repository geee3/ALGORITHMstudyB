/*
by GEEE3, February 26, 2021
Linear Search를 수행하는 프로그램
요소가 직선 모양으로 늘어선 배열에서의 검색은 원하는 키 값을 갖는 요소를 만날때까지
맨 앞에서부터 순서대로 요소를 검색하면 되는데, 이것을 Linear Search 알고리즘이라 한다
반복문의 종료 조건은 다음과 같다
1. 키 값을 발견하지 못하고 배열의 끝을 지나간 경우
2. 검색할 값과 같은 요소를 발견한 경우
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