/*
by GEEE3, February 15, 2021
세 정수의 최댓값을 구하는 프로그램
최댓값을 구하는 과정은 다음과 같다
1. max에 a를 대입한다
2. b 값이 max보다 크다면 max에 b를 대입한다
3. c 값이 max보다 크다면 max에 c를 대입한다
*/

#include <stdio.h>

int calMax (int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

int main (void) {
    printf("max of %d, %d, %d is %d\n", 15, 22, 7, calMax(15, 22, 7));
    printf("max of %d, %d, %d is %d\n", 10, 9, 8, calMax(10, 9, 8));
    printf("max of %d, %d, %d is %d\n", 5, 5, 5, calMax(5, 5, 5));
    printf("max of %d, %d, %d is %d\n", 23, -6, 14, calMax(23, -6, 14));
    printf("max of %d, %d, %d is %d\n", -10, -20, -30, calMax(-10, -20, -30));
    return 0;
}