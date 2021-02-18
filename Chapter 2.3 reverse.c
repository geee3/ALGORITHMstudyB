/*
by GEEE3, February 18, 2021
배열 요소를 역순으로 정렬하는 프로그램
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* type형 x와 y 값을 교환 */
#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)

/* 크기가 n인 배열 ary의 요소를 역순으로 정렬 */
void reverseAry (int ary[], int na) {
    int i;
    for (i = 0; i < na / 2; i++) {
        swap(int, ary[i], ary[na - i - 1]);
    }
}

int main (void) {
    int i, na;
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

    reverseAry(ary, na);
    printf("reverse : ");
    for (i = 0; i < na; i++) {
        printf("%d ", ary[i]);
    }
    printf("\n");

    free(ary);
}