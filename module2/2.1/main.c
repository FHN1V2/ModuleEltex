#include <stdio.h>
#include <string.h>
#include "contacts.h"

void display_menu() {
    printf("\nТелефонная книга:\n");
    printf("1. Добавить контакт\n");
    printf("2. Редактировать контакт\n");
    printf("3. Удалить контакт\n");
    printf("4. Показать все контакты\n");
    printf("5. Выход\n");
    printf("Выберите действие: ");
}
int main() {
    int choice;
    char first_name[MAX_FIELD_LEN]; 
    char last_name[MAX_FIELD_LEN];
    int id;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                printf("Введите ID контакта для редактирования: ");
                scanf("%d", &id);
                getchar();
                edit_contact(id);
                break;
            case 3:
                printf("Введите ID контакта для удаления: ");
                scanf("%d", &id);
                getchar();
                delete_contact(id);
                break;
            case 4:
                print_contacts();
                break;
            case 5:
                return 0;
            default:
                printf("Неверный выбор!\n");
        }
    }
}