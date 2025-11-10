#include "perm.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Использование:\n");
        printf("  %s <файл>             - показать права файла (аналог ls -l)\n", argv[0]);
        printf("  %s <файл> <команда>   - изменить права (например +x, u+w,g-r)\n", argv[0]);
        printf("  %s <права>            - показать битовое и цифровое представление (напр. 755 или rwxr-xr--)\n", argv[0]);
        return 1;
    }
    // Если введён только 1 аргумент — это либо имя файла, либо маска прав
    if (argc == 2) {
        struct stat st;
        // Проверяем, существует ли файл
        if (stat(argv[1], &st) == 0) {
            show_file_permissions(argv[1]);
        } else {
            // Не файл — значит, права вручную
            mode_t mode;
            if (isdigit(argv[1][0]))
                mode = parse_octal_perms(argv[1]);
            else
                mode = parse_symbolic_perms(argv[1]);
            print_perm_modes(mode);
        }
    }

    // Если введено 2 аргумента (файл и команда)
    if (argc == 3) {
        struct stat st;


        mode_t mode = st.st_mode;
        mode_t new_mode = modify_perms(mode, argv[2]);
        printf("Исходные права:\n");
        print_perm_modes(mode);
        printf("\nПосле применения команды '%s':\n", argv[2]);
        print_perm_modes(new_mode);
        printf("\n(Изменения не применяются к файлу — только показываются)\n");
    }

    else {
        fprintf(stderr, "Ошибка: слишком много аргументов.\n");
        return 1;
    }

    return 0;
}
