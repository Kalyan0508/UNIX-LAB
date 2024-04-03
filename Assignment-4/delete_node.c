//delete_node.c:

#include <stdio.h>
#include <stdlib.h>
#include "unique_functions.h"

void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    Node* prev = NULL;
    
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    
    // Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in linked list
    if (temp == NULL) {
        printf("Key not found in the linked list\n");
        return;
    }
    
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}



