/*
by GEEE3, February 24, 2021
num 이하의 소수를 출력하는 프로그램
*/

#include <stdio.h>
#include <math.h>

int main (void) {
    int i, j, n, num, flag, count = 0;
    int prime[1000];

    prime[count++] = 2;
    prime[count++] = 3;
    
    printf("num 이하의 소수를 출력하는 프로그램입니다. num : ");
    scanf("%d", &num);

    for (n = 5; n <= num; n += 2) {
        flag = 0;
        for (i = 0; i < count; i++) {
            if (n % prime[i] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            prime[count++] = n;
        }
    }
    
    printf("%d 이하의 수 가운데 소수는 총 %d개로 다음과 같습니다.\n[", num, count);
    for (i = 0; i < count - 1; i++) {
        printf("%d ", prime[i]);
    }
    printf("%d]\n", prime[count - 1]);
}