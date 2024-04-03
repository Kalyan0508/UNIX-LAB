#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node with given key from the linked list
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    Node* prev = NULL;
    
    // Introduce segmentation fault
    char* ptr = NULL;
    *ptr = 'x';

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

int main() {
    Node* head = NULL;

    // Insert some elements into the linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    // Display the linked list
    printf("Linked list: ");
    display(head);

    // Delete a node with key 10
    deleteNode(&head, 10);

    // Display the updated linked list
    printf("Linked list after deletion: ");
    display(head);

    return 0;
}

