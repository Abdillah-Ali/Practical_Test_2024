#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Stack {
    int data[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    }
}

int pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

void reverseList(int *list, int n) {
    struct Stack s;
    initStack(&s);
    for (int i = 0; i < n; i++) {
        push(&s, list[i]);
    }
    for (int i = 0; i < n; i++) {
        list[i] = pop(&s);
    }
}

int main() {
    int list[] = {45, 67, 89, 123, 456};
    int n = sizeof(list) / sizeof(list[0]);
    printf("Original list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    reverseList(list, n);
    printf("Reversed list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
