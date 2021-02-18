/*
by GEEE3, February 18, 2021
배열의 요소 개수를 실행 시점에 결정하고, for문으로 반복하여 요소의 값을 출력하는 프로그램
calloc 함수는 확보한 메모리의 첫 번째 주소를 반환하고, 그 값은 포인터 a에 대입된다
이때 포인터와 배열은 서로 바꾸어 쓸 수 있다 즉, 포인터를 배열인 것처럼 사용할 수 있다
*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int i, na;
    int *ary;
    printf("size of array : ");
    scanf("%d", &na);
    ary = calloc (na, sizeof(int));

    if (ary == NULL) {
        printf("memory ERROR");
        return 0;
    }
    else {
        for (i = 0; i < na; i++) {
            ary[i] = i;
        }
    }

    printf("array : [");
    for (i = 0; i < na - 1; i++) {
        printf("%d ", ary[i]);
    }
    printf("%d]\n", ary[na - 1]);

    free(ary);
}