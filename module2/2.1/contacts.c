#include <stdio.h>
#include <string.h>
#include "contacts.h"

Contact contacts[MAX_CONTACTS];
int contact_count = 0;
int next_id = 1;

void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Достигнут максимум контактов!\n");
        return;
    }

    Contact new_contact = {0};
    new_contact.id = next_id++; 

    printf("Введите фамилию: ");
    fgets(new_contact.last_name, MAX_FIELD_LEN, stdin);
    new_contact.last_name[strcspn(new_contact.last_name, "\n")] = 0;

    printf("Введите имя: ");
    fgets(new_contact.first_name, MAX_FIELD_LEN, stdin);
    new_contact.first_name[strcspn(new_contact.first_name, "\n")] = 0;

    printf("Введите отчество (если нет, нажмите Enter): ");
    fgets(new_contact.middle_name, MAX_FIELD_LEN, stdin);
    new_contact.middle_name[strcspn(new_contact.middle_name, "\n")] = 0;

    printf("Введите место работы (если нет, нажмите Enter): ");
    fgets(new_contact.job, MAX_FIELD_LEN, stdin);
    new_contact.job[strcspn(new_contact.job, "\n")] = 0;

    printf("Введите должность (если нет, нажмите Enter): ");
    fgets(new_contact.position, MAX_FIELD_LEN, stdin);
    new_contact.position[strcspn(new_contact.position, "\n")] = 0;

    printf("Введите номера телефонов (до %d, для завершения введите '0'):\n", MAX_PHONES);
    for (int i = 0; i < MAX_PHONES; i++) {
        char input[MAX_FIELD_LEN];
        printf("Телефон %d: ", i + 1);
        fgets(input, MAX_FIELD_LEN, stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "0") == 0) break;
        strcpy(new_contact.phone_list.phones[i], input);
        new_contact.phone_list.phone_count++;
    }

    printf("Введите адреса почты (до %d, для завершения введите '0'):\n", MAX_EMAILS);
    for (int i = 0; i < MAX_EMAILS; i++) {
        char input[MAX_FIELD_LEN];
        printf("Email %d: ", i + 1);
        fgets(input, MAX_FIELD_LEN, stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "0") == 0) break;
        strcpy(new_contact.email_list.emails[i], input);
        new_contact.email_list.email_count++;
    }

    printf("Введите соцсети (до %d, для завершения введите '0'):\n", MAX_SOCIALS);
    for (int i = 0; i < MAX_SOCIALS; i++) {
        char input[MAX_FIELD_LEN];
        printf("Соцсеть %d: ", i + 1);
        fgets(input, MAX_FIELD_LEN, stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "0") == 0) break;
        strcpy(new_contact.social_list.socials[i], input);
        new_contact.social_list.social_count++;
    }

    printf("Введите мессенджеры (до %d, для завершения введите '0'):\n", MAX_MESSENGERS);
    for (int i = 0; i < MAX_MESSENGERS; i++) {
        char input[MAX_FIELD_LEN];
        printf("Мессенджер %d: ", i + 1);
        fgets(input, MAX_FIELD_LEN, stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "0") == 0) break;
        strcpy(new_contact.messenger_list.messengers[i], input);
        new_contact.messenger_list.messenger_count++;
    }

    contacts[contact_count++] = new_contact;
    printf("Контакт добавлен! ID: %d\n", new_contact.id);
}

void edit_contact(int id) {
    int index = find_contact_by_id(id);
    if (index == -1) {
        printf("Контакт с ID %d не найден!\n", id);
        return;
    }

    Contact *c = &contacts[index];
    printf("Редактирование контакта ID %d: %s %s\n", c->id, c->first_name, c->last_name);

    printf("Введите новую фамилию [%s]: ", c->last_name);
    char input[MAX_FIELD_LEN];
    fgets(input, MAX_FIELD_LEN, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strlen(input) > 0) strcpy(c->last_name, input);

    printf("Введите новое имя [%s]: ", c->first_name);
    fgets(input, MAX_FIELD_LEN, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strlen(input) > 0) strcpy(c->first_name, input);

    printf("Введите новое отчество [%s]: ", c->middle_name);
    fgets(input, MAX_FIELD_LEN, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strlen(input) > 0) strcpy(c->middle_name, input);

    printf("Введите новое место работы [%s]: ", c->job);
    fgets(input, MAX_FIELD_LEN, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strlen(input) > 0) strcpy(c->job, input);

    printf("Введите новую должность [%s]: ", c->position);
    fgets(input, MAX_FIELD_LEN, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strlen(input) > 0) strcpy(c->position, input);

    printf("Контакт обновлен!\n");
}

void delete_contact(int id) {
    int index = find_contact_by_id(id);
    if (index == -1) {
        printf("Контакт с ID %d не найден!\n", id);
        return;
    }

    // Сохраняем ID для сообщения
    int deleted_id = contacts[index].id;

    for (int i = index; i < contact_count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contact_count--;
    printf("Контакт с ID %d удален!\n", deleted_id);
}

void print_contacts() {
    printf("\nСписок контактов:\n");
    for (int i = 0; i < contact_count; i++) {
        Contact *c = &contacts[i];
        printf("ID: %d. %s %s %s\n", c->id, c->last_name, c->first_name, c->middle_name);
        printf("   Работа: %s, Должность: %s\n", c->job, c->position);
        
        printf("   Телефоны: ");
        for (int j = 0; j < c->phone_list.phone_count; j++) 
            printf("%s; ", c->phone_list.phones[j]);
        
        printf("\n   Emails: ");
        for (int j = 0; j < c->email_list.email_count; j++) 
            printf("%s; ", c->email_list.emails[j]);
        
        printf("\n   Соцсети: ");
        for (int j = 0; j < c->social_list.social_count; j++) 
            printf("%s; ", c->social_list.socials[j]);
        
        printf("\n   Мессенджеры: ");
        for (int j = 0; j < c->messenger_list.messenger_count; j++) 
            printf("%s; ", c->messenger_list.messengers[j]);
        
        printf("\n\n");
    }
}

int find_contact_by_id(int id) {
    for (int i = 0; i < contact_count; i++) {
        if (contacts[i].id == id) {
            return i;
        }
    }
    return -1;
}

int find_contact_by_name(const char* first_name, const char* last_name) {
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].first_name, first_name) == 0 && 
            strcmp(contacts[i].last_name, last_name) == 0) {
            return i;
        }
    }
    return -1;
}