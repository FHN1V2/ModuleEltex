#include <stdio.h>
#include "priority.h"

int main() {
    PriorityQueue q;
    initQueue(&q);
    Node* node;
    // Добавление элементов
    enqueue(&q, "Сообщение 1", 0);
    enqueue(&q, "Сообщение 2", 1);
    enqueue(&q, "Сообщение 3", 32);
    enqueue(&q, "Сообщение 4", 153);
    enqueue(&q, "Сообщение 5", 66);
    enqueue(&q, "Сообщение 6", 53);
    enqueue(&q, "Сообщение 7", 240);
    enqueue(&q, "Сообщение 8", 240);
    enqueue(&q, "Сообщение 9", 2);
    enqueue(&q, "Сообщение 10", 0);
    
    printQueue(&q);
    
    printf("\n--- Извлечение по наивысшему приоритету ---\n");
    node = dequeue(&q);
    if (node) {
        printf("Извлечено: [Приоритет %d] %s\n", node->priority, node->message);
    }
    
    node = dequeue(&q);
    if (node) {
        printf("Извлечено: [Приоритет %d] %s\n", node->priority, node->message);

    }
    

    printQueue(&q);
    
    // Извлечение по конкретному приоритету
    printf("\n--- Извлечение по приоритету 1 ---\n");
    node = dequeueByPriority(&q, 1);
    if (node) {
        printf("Извлечено: [Приоритет %d] %s\n", node->priority, node->message);

    } else {
        printf("Нет элементов с приоритетом 1\n");
    }

    // Извлечение по приоритету не ниже заданного
    node = dequeueByPriority(&q, 1);
    if (node) {
        printf("Извлечено: [Приоритет %d] %s\n", node->priority, node->message);

    } else {
        printf("Нет элементов с приоритетом 1\n");
    }


    printf("\n--- Извлечение с приоритетом не ниже 2 ---\n");
    node = dequeueAtLeastPriority(&q, 2);
    if (node) {
        printf("Извлечено: [Приоритет %d] %s\n", node->priority, node->message);

    } else {
        printf("Нет элементов с приоритетом не ниже 2\n");
    }
    
    printf("\n--- Финальное состояние очереди ---\n");
    printQueue(&q);
    
    
    return 0;
}