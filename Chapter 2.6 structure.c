/*
by GEEE3, February 26, 2021
신체검사 데이터를 저장하는 구조체 배열
*/

#include <stdio.h>

/* 신체검사 구조체 */
typedef struct {
    char name[20];
    int height;
    double vision;
} physCheck;

/* 키의 평균을 구하는 함수 */
double aveHeight (physCheck dat[], int num) {
    int i;
    double sum = 0;

    for (i = 0; i < num; i++) {
        sum += dat[i].height;
    }

    return sum / num;
}

int main (void) {
    int i;
    physCheck student[] = {
        {"Elizabeth", 163, 1.0},
        {"Mary", 160, 2.1},
        {"James", 181, 1.5},
        {"John", 177, 1.2},
        {"Amanda", 158, 0.3},
        {"Donald", 175, 0.8},
        {"Sarah", 162, 2.0},
        {"Matthew", 179, 1.8},
    };

    int num = sizeof(student) / sizeof(student[0]);
    printf("Physical Examination : \n");
    printf("     name     height     vision\n");
    
    for (i = 0; i < num; i++){
        printf("%9s %10d %10.1f\n", student[i].name, student[i].height, student[i].vision);
    }
    printf("Average Height : %5.1f\n", aveHeight(student, num));

    return 0;
}