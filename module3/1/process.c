#include "process.h"

int is_number(const char *str) 
{
    if (str == NULL || *str == '\0') 
    {
        return 0;
    }
    
    int has_dot = 0;
    int has_digit = 0;
    
    if (*str == '-') 
    {
        str++;
    }
    
    while (*str) 
    {
        if (isdigit(*str)) 
        {
            has_digit = 1;
        } 
        else if (*str == '.') 
        {
            if (has_dot) 
            {
                return 0;
            }
            has_dot = 1;
        } 
        else 
        {
            return 0; 
        }
        str++;
    }   
    return has_digit;
}

void process_arguments(char *args[], int start, int end) 
{
    for (int i = start; i < end; i++) 
    {
        if (is_number(args[i])) 
        {
            double num = atof(args[i]);
            printf(" %s -->> %f\n", args[i], num * 2);
        } 
        else 
        {
            printf(" %s\n", args[i]);
        }
    }
}

void process_with_fork(char *argv[], int argc) 
{
    if (argc <= 1)
    {
        printf("Не указаны аргументы для обработки\n");
        return;
    }
    int mid = argc / 2;

    pid_t pid = fork();

    if (pid == 0)
    {
        printf(" Дочерний процесс (PID: %d) \n", getpid());
        process_arguments(argv, mid + 1, argc);
        printf(" Дочерний процесс завершен \n");
    }
    else 
    {
        printf(" Родительский процесс (PID: %d) \n", getpid());
        process_arguments(argv, 1, mid + 1);
        int status;
        waitpid(pid, &status, 0);
        printf(" Родительский процесс завершен \n");
    }

}