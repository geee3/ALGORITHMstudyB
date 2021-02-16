/*
by GEEE3, February 16, 2021
1, 2 ... n의 합을 구하는 프로그램
사전 판단 반복문인 while문과 for문은 처음에 제어식을 평가한 결과가 False이면 본문은 실행되지 않는다
이와 달리 사후 판단 반복문인 do문은 루프 본문이 반드시 한 번은 실행된다
*/

#include <stdio.h>

int main (void) {
    int height, i, j;
    printf("height of TREE : ");
    scanf("%d", &height);
    printf("\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < height - i; j++) {
            printf(" ");
        }
        for (j = 0; j < 2 * (i + 1) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}