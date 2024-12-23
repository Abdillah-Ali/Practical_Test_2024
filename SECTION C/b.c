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

Node* mergeLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
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
    Node *l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    Node *l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);

    printf("List 1:\n");
    printList(l1);
    printf("List 2:\n");
    printList(l2);

    Node *merged = mergeLists(l1, l2);

    printf("Merged list:\n");
    printList(merged);

    return 0;
}
