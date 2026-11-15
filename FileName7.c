#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "RUS");

    int year;
    printf("Введите год 21 века (2001-2100): ");
    scanf("%d", &year);

    if (year < 2001 || year > 2100) {
        printf("Ошибка: год должен быть в пределах 21 века.\n");
        return 0;
    }

    int total_days = 0;

    for (int y = 2001; y < year; y++) {
        int is_leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        total_days += 365 + is_leap;
    }

    total_days += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;

    int is_leap_current = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    total_days += is_leap_current;

    int day_of_week = total_days % 7;

    switch (day_of_week) {
    case 0:
        printf("1 сентября %d года — это понедельник.\n", year);
        break;
    case 1:
        printf("1 сентября %d года — это вторник.\n", year);
        break;
    case 2:
        printf("1 сентября %d года — это среда.\n", year);
        break;
    case 3:
        printf("1 сентября %d года — это четверг.\n", year);
        break;
    case 4:
        printf("1 сентября %d года — это пятница.\n", year);
        break;
    case 5:
        printf("1 сентября %d года — это суббота.\n", year);
        break;
    case 6:
        printf("1 сентября %d года — это воскресенье.\n", year);
        break;
    }

    return 0;
}