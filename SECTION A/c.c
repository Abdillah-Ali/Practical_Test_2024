#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Student {
    char name[50];
    int age;
} Student;

typedef struct Stack {
    Student data[MAX];
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

void push(Stack *s, Student student) {
    if (!isFull(s)) {
        s->data[++(s->top)] = student;
    }
}

Student pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    Student empty = {"", -1};
    return empty;
}

int main() {
    Stack s;
    initStack(&s);

    Student students[] = {{"Alice", 13}, {"Bob", 17}, {"Charlie", 22}};
    int n = sizeof(students) / sizeof(students[0]);

    for (int i = 0; i < n; i++) {
        push(&s, students[i]);
    }

    printf("Students popped from stack:\n");
    while (!isEmpty(&s)) {
        Student student = pop(&s);
        printf("Name: %s, Age: %d\n", student.name, student.age);
    }

    return 0;
}
