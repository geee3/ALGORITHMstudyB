/*
by GEEE3, February 16, 2021
tree의 높이 height를 입력받아 tree를 출력하는 프로그램
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