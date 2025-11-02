#ifndef CALC_H
#define CALC_H

double add(int n, ...);
double subtract(int n, ...);
double multiply(int n, ...);
double divide(int n, ...);
void display_menu();

// --- Макрос для вызова функции с переменным числом аргументов ---
#define CALL_FUNC(func, n, values) \
    ((n) == 1 ? (values)[0] : \
    (n) == 2 ? func(2, (values)[0], (values)[1]) : \
    (n) == 3 ? func(3, (values)[0], (values)[1], (values)[2]) : \
    (n) == 4 ? func(4, (values)[0], (values)[1], (values)[2], (values)[3]) : \
    (n) == 5 ? func(5, (values)[0], (values)[1], (values)[2], (values)[3], (values)[4]) : 0)

#endif