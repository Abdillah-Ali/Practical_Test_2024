#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void removeDuplicates(Node* head) {
    Node* current = head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d , ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(5);

    printf("Original list:\n");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates:\n");
    printList(head);

    return 0;
}
