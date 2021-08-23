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
    char data;
    struct Node* next;
};

void addNode(struct Node* head, char newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    struct Node *last = head;

    if(head == NULL) {
        head = newNode;
        return;
    }
    
    while(last->next != NULL)
        last = last->next;
    last->next = newNode;
}

void deleteNode(struct Node** head, char key) {
    struct Node *tempNode = *head;
    struct Node *prevNode = NULL;

    if(tempNode != NULL && tempNode->data == key) {
        *head = tempNode->next;
        free(tempNode);
        return;
    }

    while(tempNode != NULL && tempNode -> data != key) {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }

    if(tempNode == NULL) {
        printf("\n");
        printf("ERROR: No Matching Data\n");
        return;
    }
    prevNode->next = tempNode->next;
    free(tempNode);
}

void printList(struct Node* head) {
    struct Node* node = head;
    while(1) {
        printf("+---+\n");
        printf("| %c |\n", node->data);
        printf("+---+\n");
        printf("\n");

        if(node->next == NULL)
            break;
        printf("  |\n");
        printf("  V\n");
        printf("\n");
        node = node->next;
    }
}

int main(void) {
    int command, endFlag = 0;
    char userInput;
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 'a';
    head->next = second;
    second->data = 'b';
    second->next = third;
    third->data = 'c';
    third->next = NULL;

    printList(head);

    while(endFlag == 0) {
        printf("[Please Enter Number to Execute]\n");
        printf("1. Add Data.\n");
        printf("2. Delete Data.\n");
        printf("3. Print List.\n");
        printf("4. Terminate.\n");
        scanf("%d", &command);
        getchar();
        printf("\n");

        switch(command) {
            case 1:
                printf("Please Enter Alphabet to Add: ");
                scanf("%c", &userInput);
                getchar();
                addNode(head, userInput);
                printf("\n");
                break;
            case 2:
                printf("Please Enter Alphabet to Delete: ");
                scanf("%c", &userInput);
                getchar();
                deleteNode(&head, userInput);
                printf("\n");
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("[Program Termination...]");
                endFlag = 1;
                break;
        }
    }
    return 0;
}