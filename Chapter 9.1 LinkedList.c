/*
by GEEE3, August 19, 2021
Like arrays, Linked List is a linear data structure
Unlike arrays, linked list elements are not stored at a contiguous location
A linked list is represented by a pointer to the first node of the linked list
The first node is called the head
If the linked list is empty, then the value of the head is NULL

Why Linked List:
1. Dynamic size
2. Ease of insertion/delection

Drawbacks:
1. Random access is not allowed
We have to access elements sequentially starting from the first node
So we cannot do binary search with linked list efficiently
2. Extra momory space for a pointer is required with each element of the list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* node = head;
    while(1) {
        printf("+---+\n");
        printf("| %d |\n", node->data);
        printf("+---+\n");
        if(node->next == NULL)
            break;
        printf("\n");
        printf("  |\n");
        printf("  V\n");
        printf("\n");
        node = node->next;
    }
}

int main(void) {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);
    return 0;
}