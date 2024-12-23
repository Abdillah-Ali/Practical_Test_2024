#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue {
    int data[MAX];
    int front, rear, size;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isFull(Queue *q) {
    return q->size == MAX;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, int value) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = value;
        q->size++;
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        int value = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->size--;
        return value;
    }
    return -1;
}

int findMax(Queue *q) {
    int max = -1;
    int n = q->size;

    for (int i = 0; i < n; i++) {
        int value = dequeue(q);
        if (value > max) max = value;
        enqueue(q, value);  // Re-enqueue to preserve the queue
    }

    return max;
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 17);
    enqueue(&q, 2);
    enqueue(&q, 5);
    enqueue(&q, 3);

    printf("Max element in the queue: %d\n", findMax(&q));

    return 0;
}
