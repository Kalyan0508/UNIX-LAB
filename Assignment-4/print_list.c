//print_list.c:

#include <stdio.h>
#include "unique_functions.h"

void printList(Node* head) {
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


