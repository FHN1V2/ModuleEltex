#include "calc.h"
#include <stdio.h>

int main() {
    // Таблица доступных операций
    Operation ops[] = {
        {add},
        {subtract},
        {multiply},
        {divide}
    };

    int op_count = sizeof(ops) / sizeof(ops[0]);
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        if (choice == op_count + 1) break;
        if (choice < 1 || choice > op_count + 1) {
            printf("Неверный выбор!\n");
            continue;
        }

        int n;
        printf("Количество аргументов (1–5): ");
        scanf("%d", &n);
        if (n <= 0 || n > 5) {
            printf("Поддерживаются от 1 до 5 аргументов!\n");
            continue;
        }

        double values[n];
        for (int i = 0; i < n; i++) {
            printf("Введите число %d: ", i + 1);
            scanf("%lf", &values[i]);
        }

        // Получаем указатель на выбранную функцию
        calc_func func = ops[choice - 1].func;
        double result = CALL_FUNC(func, n, values);

        printf("Результат: %.2lf\n", result);
    }

    printf("Выход из программы.\n");
    return 0;
}
