#ifndef CALC_H
#define CALC_H

// Тип функции с переменным числом аргументов
typedef double (*calc_func)(int, ...);

// Структура описания операции
typedef struct {
//   const char* name;
    calc_func func;
} Operation;

// Функции
double add(int n, ...);
double subtract(int n, ...);
double multiply(int n, ...);
double divide(int n, ...);

void display_menu();

#define CALL_FUNC(func, n, values) \
    ((n) == 1 ? (values)[0] : \
    (n) == 2 ? func(2, (values)[0], (values)[1]) : \
    (n) == 3 ? func(3, (values)[0], (values)[1], (values)[2]) : \
    (n) == 4 ? func(4, (values)[0], (values)[1], (values)[2], (values)[3]) : \
    (n) == 5 ? func(5, (values)[0], (values)[1], (values)[2], (values)[3], (values)[4]) : 0)

#endif
