/*
by GEEE3, February 24, 2021
한 해의 지난 날 수를 계산하는 프로그램
*/

#include <stdio.h>

/* year가 윤년임을 판단하는 함수 */
int leapYear (int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/* 2차원 배열을 사용해 한 해의 지난 날 수를 계산하는 함수 */
int dayOfYear (int year, int month, int day) {
    int months[][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    int i, days;
    days = day;

    for (i = 0; i < month - 1; i++) {
        days += months[leapYear(year)][i];
    }

    return days;
}

int main (void) {
    int year, month, day;
    printf("YEAR : ");
    scanf("%d", &year);
    printf("MONTH : ");
    scanf("%d", &month);
    printf("DAY : ");
    scanf("%d", &day);

    switch(dayOfYear(year, month, day)) {
        case 1:
            printf("Today is first day of the year.\n");
            break;
        case 2:
            printf("Today is second day of the year.\n");
            break;
        case 3:
            printf("Today is third day of the year.\n");
            break;
        default:
            printf("Today is %dth day of the year.\n", dayOfYear(year, month, day));
            break;
    }

    return 0;
}