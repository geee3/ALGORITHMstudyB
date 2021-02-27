/*
by GEEE3, February 27, 2021
함수 포인터를 사용하여 덧셈표와 곱셈표를 출력하는 프로그램
*/

#include <stdio.h>

int add (int num1, int num2) {
    return num1 + num2;
}

int mul (int num1, int num2) {
    return num1 * num2;
}

void table (int(*cal)(int, int)) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (j == 0)
                printf("%d", (*cal)(i, j));
            else 
                printf("%4d", (*cal)(i, j));
        }
        printf("\n");
    }
}

int main (void) {
    printf("Addition Table :\n");
    table(add);
    printf("\n");
    printf("Multiplication Table :\n");
    table(mul);
    return 0;
}