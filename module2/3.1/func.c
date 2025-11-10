#include "perm.h"
// символьные 
mode_t parse_octal_perms(const char *perm_str) {
    return strtol(perm_str, NULL, 8);
}

// буквенные
mode_t parse_symbolic_perms(const char *perm_str) {
    if (strlen(perm_str) != 9) {
        fprintf(stderr, "Ошибка: буквенное представление должно содержать 9 символов\n");
        return 0;
    }

    mode_t mode = 0;
    const char symbols[] = {'r', 'w', 'x'};
    for (int i = 0; i < 9; i++) {
        if (perm_str[i] == symbols[i % 3])
            mode |= 1 << (8 - i);
    }
    return mode;
}

// Вывод прав доступа
void print_perm_modes(mode_t mode) {
    char letters[10];
    const char rwx[] = {'r', 'w', 'x'};
    for (int i = 0; i < 9; i++)
        letters[i] = (mode & (1 << (8 - i))) ? rwx[i % 3] : '-';
    letters[9] = '\0';

    printf("Буквенное представление: %s\n", letters);
    printf("Цифровое (восьмеричное): %03o\n", mode & 0777);
    printf("Битовое представление:   ");
    for (int i = 8; i >= 0; i--)
        printf("%d", (mode & (1 << i)) ? 1 : 0);
    printf("\n");
}

// Показать права файла
void show_file_permissions(const char *filename) {
    struct stat st;
    if (stat(filename, &st) != 0) {
        perror("stat");
        return;
    }

    printf("Файл: %s\n", filename);
    print_perm_modes(st.st_mode);
}

// Изменение прав
mode_t modify_perms(mode_t current, const char *cmd) {
    char *commands = strdup(cmd);
    char *token = strtok(commands, ",");

    while (token) {
        char who[5] = {0}, op = 0, perms[5] = {0};
        int i = 0, j = 0;

        // Разбор вида u+x,g-w,o+r
        while (token[i] && strchr("ugo", token[i])) {
            who[j++] = token[i++];
        }
        if (token[i] == '+' || token[i] == '-') {
            op = token[i++];
        }

        strcpy(perms, token + i);

        for (int w = 0; who[w]; w++) {
            int shift = 0;
            switch (who[w]) {
                case 'u': shift = OWNER_SHIFT; break;
                case 'g': shift = GROUP_SHIFT; break;
                case 'o': shift = OTHER_SHIFT; break;
                default: continue;
            }

            for (int p = 0; perms[p]; p++) {
                mode_t mask = 0;
                switch (perms[p]) {
                    case 'r': mask = 4 << shift; break;
                    case 'w': mask = 2 << shift; break;
                    case 'x': mask = 1 << shift; break;
                    default: continue;
                }

                if (op == '+')
                    current |= mask;
                else if (op == '-')
                    current &= ~mask;
            }
        }
        token = strtok(NULL, ",");
    }

    free(commands);
    return current;
}
