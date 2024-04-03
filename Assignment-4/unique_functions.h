//unique_functions.h:

#ifndef UNIQUE_FUNCTIONS_H
#define UNIQUE_FUNCTIONS_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
void deleteNode(Node** headRef, int key);
void printList(Node* head);

#endif /* UNIQUE_FUNCTIONS_H */


