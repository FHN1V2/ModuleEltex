#include "calc.h"
#include <stdio.h>
#include <stdarg.h>

int main() {
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        if (choice == 5) break;
        int n;
        printf("Количество аргументов: "); 
        scanf("%d", &n);
        if (n <= 0 || n > 5) 
        { 
            printf("Поддерживаются от 1 до 5 аргументов\n");
            continue;
        }
        double values[n];
        for (int i = 0; i < n; i++) 
        { 
            printf("Введите число %d: ", i+1);
            scanf("%lf", &values[i]); 
        }
        double result = 0;
        switch (choice) {
            case 1: 
                result = CALL_FUNC(add, n, values); 
                break;
            case 2: 
                result = CALL_FUNC(subtract, n, values);  
                break;
            case 3: 
                result = CALL_FUNC(multiply, n, values); 
                break;
            case 4: 
                result = CALL_FUNC(divide, n, values);
                break;
            default: 
                printf("Неверный выбор\n"); 
                continue;
        }

        printf("Результат: %.2lf\n", result);
    }
    return 0;
}