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


    void display_menu() {
    printf("\n    Калькулятор   \n");
    printf("1. Сложение\n");
    printf("2. Вычитание\n");
    printf("3. Умножение\n");
    printf("4. Деление\n");
    printf("5. Выход\n");
    printf("Введите операцию: ");
}