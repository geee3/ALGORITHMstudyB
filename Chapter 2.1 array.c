/*
by GEEE3, February 18, 2021
배열의 요소 개수와 각 요소의 값을 출력하는 프로그램
sizeof(array)로 전체 배열이 할당된 크기를 구하고 sizeof(array[])를 이용해 각각의 메모리 크기를 구할수 있으므로
이를 이용하면 sizeof(array) / sizeof(array[])를 통해 배열의 요소 개수를 구할 수 있다
*/

#include <stdio.h>

int main (void) {
    int i;
    int ary[5] = {10, 11, 12, 13, 14};
    int na = sizeof(ary) / sizeof(ary[0]);
    printf("배열 ary의 요소 개수는 %d입니다.\n", na);

    for (i = 0; i < na; i++) {
        printf("a[%d] = %d ", i, ary[i]);
    }
    printf("\n");
}