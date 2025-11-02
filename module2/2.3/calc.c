#include <stdio.h>
#include <stdarg.h>
#include "calc.h"

double add(int n, ...) {
    va_list args; 
    va_start(args, n);
    double result = 0;
    for (int i = 0; i < n; i++) result += va_arg(args, double);
    va_end(args);
    return result;
}

double subtract(int n, ...) {
    va_list args; 
    va_start(args, n);
    double result = va_arg(args, double);
    for (int i = 1; i < n; i++) result -= va_arg(args, double);
    va_end(args);
    return result;
}

double multiply(int n, ...) {
    va_list args; 
    va_start(args, n);
    double result = 1;
    for (int i = 0; i < n; i++) result *= va_arg(args, double);
    va_end(args);
    return result;
}

double divide(int n, ...) {
    va_list args;
    va_start(args, n);
    double result = va_arg(args, double);
    for (int i = 1; i < n; i++) {
        double next = va_arg(args, double);
        if (next == 0) { 
            printf("Ошибка: деление на ноль!\n");
            va_end(args);
            return 0;
        }
        result /= next;
    }
    va_end(args);
    return result;
}

void display_menu(Operation ops[], int count) {
    printf("\n   Калькулятор   \n");
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, ops[i].name);
    printf("%d. Выход\n", count + 1);
    printf("Выберите операцию: ");
}
