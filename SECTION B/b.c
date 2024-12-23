#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    Node *front;
    Node *rear;
} Deque;

void initDeque(Deque *dq) {
    dq->front = dq->rear = NULL;
}

int isEmpty(Deque *dq) {
    return dq->front == NULL;
}

void enqueueFront(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = dq->front;
    newNode->prev = NULL;

    if (isEmpty(dq)) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }

    dq->front = newNode;
}

void enqueueRear(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (isEmpty(dq)) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }

    dq->rear = newNode;
}

int dequeueFront(Deque *dq) {
    if (isEmpty(dq)) return -1;

    Node *temp = dq->front;
    int value = temp->data;

    dq->front = dq->front->next;
    if (dq->front) {
        dq->front->prev = NULL;
    } else {
        dq->rear = NULL;
    }

    free(temp);
    return value;
}

int dequeueRear(Deque *dq) {
    if (isEmpty(dq)) return -1;

    Node *temp = dq->rear;
    int value = temp->data;

    dq->rear = dq->rear->prev;
    if (dq->rear) {
        dq->rear->next = NULL;
    } else {
        dq->front = NULL;
    }

    free(temp);
    return value;
}

int main() {
    Deque dq;
    initDeque(&dq);

    enqueueRear(&dq, 10);
    enqueueRear(&dq, 20);
    enqueueFront(&dq, 5);

    printf("Dequeue front: %d\n", dequeueFront(&dq));
    printf("Dequeue rear: %d\n", dequeueRear(&dq));

    return 0;
}
