/*
by GEEE3, February 16, 2021
1, 2 ... n의 합을 구하는 프로그램
사전 판단 반복문인 while문과 for문은 처음에 제어식을 평가한 결과가 False이면 본문은 실행되지 않는다
이와 달리 사후 판단 반복문인 do문은 루프 본문이 반드시 한 번은 실행된다
*/

#include <stdio.h>

int main (void) {
    int i, n;
    int sum = 0;
    printf("1부터 n까지의 합을 구합니다.\n");
    do {
        printf("n 값을 입력해 주세요 : ");
        scanf("%d", &n);
    } while (n <= 0);
    for (i = 0; i < n; i++) {
        sum = sum + i + 1;
    }
    printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);
    return 0;
}