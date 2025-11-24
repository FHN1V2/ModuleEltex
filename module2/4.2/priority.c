#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priority.h"

// Инициализация очереди
void initQueue(PriorityQueue* q) {
    for (int i = 0; i < MAX_PRIORITY; i++)
        q->heads[i] = NULL;
}

// Добавление элемента
void enqueue(PriorityQueue* q, const char* msg, int priority) {
    if (priority < 0 || priority >= MAX_PRIORITY) {
        printf("Ошибка: недопустимый приоритет %d\n", priority);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->message, msg);
    newNode->priority = priority;
    newNode->next = NULL;

    if (!q->heads[priority]) {
        q->heads[priority] = newNode;
    } else {
        Node* temp = q->heads[priority];
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Извлечение первого элемента по наивысшему приоритету
Node* dequeue(PriorityQueue* q) {
    for (int i = 0; i < MAX_PRIORITY; i++) {
        if (q->heads[i]) {
            Node* temp = q->heads[i];
            q->heads[i] = q->heads[i]->next;
            return temp;
        }
    }
    return NULL;
}

// Извлечение по конкретному приоритету
Node* dequeueByPriority(PriorityQueue* q, int priority) {
    if (priority < 0 || priority >= MAX_PRIORITY || !q->heads[priority])
        return NULL;

    Node* temp = q->heads[priority];
    q->heads[priority] = q->heads[priority]->next;
    return temp;
}

// Извлечение по приоритету не ниже заданного
Node* dequeueAtLeastPriority(PriorityQueue* q, int minPriority) {
    for (int i = minPriority; i < MAX_PRIORITY; i++) {
        if (q->heads[i]) {
            Node* temp = q->heads[i];
            q->heads[i] = q->heads[i]->next;
            return temp;
        }
    }
    return NULL;
}

// Печать содержимого очереди
void printQueue(PriorityQueue* q) {
    printf("\n=== Содержимое очереди ===\n");
    for (int i = 0; i < MAX_PRIORITY; i++) {
        Node* temp = q->heads[i];
        if (temp) {
            printf("Приоритет %d: ", i);
            while (temp) {
                printf("[%s] -> ", temp->message);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}
