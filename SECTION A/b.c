#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Stack {
    char data[MAX];
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

void push(Stack *s, char ch) {
    if (!isFull(s)) {
        s->data[++(s->top)] = ch;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

int checkParentheses(const char *expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&s, expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (isEmpty(&s)) return 0;

            char top = pop(&s);
            if ((expr[i] == ')' && top != '(') ||
                (expr[i] == '}' && top != '{') ||
                (expr[i] == ']' && top != '[')) {
                return 0;
            }
        }
    }

    return isEmpty(&s);
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);

    if (checkParentheses(expr)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
