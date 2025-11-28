#include "process.h"

int main(int argc, char *argv[]) 
{
    printf("Программа запущена с %d аргументами\n", argc - 1);
    
    if (argc > 1) 
    {
        printf("Аргументы: ");
        for (int i = 1; i < argc; i++) 
        {
            printf("%s ", argv[i]);
        }
        printf("\n");
    }

    process_with_fork(argv, argc);
}