#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

int compareStacks(Stack *s1, Stack *s2) {
    if (s1->top != s2->top) {
        return 0;
    }

    for (int i = 0; i <= s1->top; i++) {
        if (s1->data[i] != s2->data[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    Stack s1, s2;
    initStack(&s1);
    initStack(&s2);

    int n1, n2, value;

    printf("Enter the number of elements in stack 1: ");
    scanf("%d", &n1);
    printf("Enter the elements of stack 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        push(&s1, value);
    }

    printf("Enter the number of elements in stack 2: ");
    scanf("%d", &n2);
    printf("Enter the elements of stack 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        push(&s2, value);
    }

    if (compareStacks(&s1, &s2)) {
        printf("The stacks are identical.\n");
    } else {
        printf("The stacks are different.\n");
    }

    return 0;
}
