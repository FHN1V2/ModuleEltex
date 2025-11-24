#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define MAX_PRIORITY 256
#define MSG_SIZE 64

typedef struct Node {
    char message[MSG_SIZE];
    int priority;
    struct Node* next;
} Node;

typedef struct {
    Node* heads[MAX_PRIORITY];
} PriorityQueue;

void initQueue(PriorityQueue* q);
void enqueue(PriorityQueue* q, const char* msg, int priority);
Node* dequeue(PriorityQueue* q);
Node* dequeueByPriority(PriorityQueue* q, int priority);
Node* dequeueAtLeastPriority(PriorityQueue* q, int minPriority);
void printQueue(PriorityQueue* q);

#endif
