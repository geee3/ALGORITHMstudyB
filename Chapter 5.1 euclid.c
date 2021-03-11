/*
by GEEE3, March 11, 2021
유클리드 호제법을 이용해 GCD를 구하는 프로그램
*/

#include <stdio.h>

int gcd (int num1, int num2) {
    if (num2 == 0)
        return num1;
    else
        return gcd(num2, num1 % num2);
}

int main (void) {
    int num1, num2, temp;
    printf("두 정수의 최대공약수를 구합니다.\n");
    printf("첫번째 정수를 입력하세요 : ");
    scanf("%d", &num1);
    printf("두번째 정수를 입력하세요 : ");
    scanf("%d", &num2);

    if (num2 > num1) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    printf("최대공약수는 %d 입니다.\n", gcd(num1, num2));
    return 0;
}