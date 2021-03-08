/*
by GEEE3, March 8, 2021
In computer science, a queue is a collection of entities that are maintained in a sequence
and can be modified by the addition of entities at one end of the sequence
and the removal of entities from the other end of the sequence
By convention, the end of the sequence at which elements are added is called the back, tail, or rear,
and the end at which elements are removed is called the head or front of the queue
The operation of adding an element to the rear of the queue is known as enqueue,
and the operation of removing an element from the front is known as dequeue
To sum up, the operations of a queue make it a first in first out, FIFO data structure
*/

#include <stdio.h>
#include <stdlib.h>

/* struct that implements the queue */
struct charQueue {
    int max; /* volume of queue */
    int front; /* front pointer */
    int rear; /* rear pointer */
    char* que; /* point of first element */
};

/* initialize queue */
struct charQueue* initialize (int max);

/* enque data in queue */
int enque (struct charQueue* q, char x);

/* deque data from queue */
int deque (struct charQueue* q);

/* peek data from queue */
int peek (struct charQueue* q, char* x);

/* return maximum capacity of queue */
int capacity (struct charQueue* q);

/* return the number of data in queue */
int size (struct charQueue* q);

/* is the queue empty? */
int isEmpty (struct charQueue* q);

/* is the queue full? */
int isFull (struct charQueue* s);

/* print all data in queue */
void print (struct charQueue* q);

/* queue termination */
void terminate (struct charQueue* q);

int main (void) {
    int max, menu = 1;
    char x;
    printf("Enter the capacity of the queue : ");
    scanf("%d", &max);
    struct charQueue* q = initialize(max);
    printf("Please enter the action to be performed\n");

    while (menu != 0) {
        printf("1. enque 2. deque 3. capacity 4. peek 5. print 0. terminate : ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("[Alphabet to Enque] : ");
                scanf(" %c", &x);
                if(enque(q, x) == -1)
                    printf("[ERROR : Queue is Full]\n");
                break;
            case 2:
                if(deque(q) == -1) {
                    printf("[ERROR : Queue is Empty]\n");
                    break;
                }
                printf("[Data Dequed]\n");
                break;
            case 3:
                printf("[Queue Capacity] : %d / %d\n", size(q), capacity(q));
                break;
            case 4:
                if(peek(q, &x) == -1) {
                    printf("[ERROR : Queue is Empty]\n");
                    break;
                }
                printf("[Data at the Front is] : %c\n", x);
                break;
            case 5:
                print(q);
                break;
            default:
                break; 
        }
    }
}

struct charQueue* initialize (int max) {
    struct charQueue* q = (struct charQueue*)malloc(sizeof(struct charQueue));
    q->front = 0;
    q->rear = 0;
    q->max = max;
    q->que = (char*)malloc(q->max * sizeof(char));
    return q;
}

int enque (struct charQueue* q, char x) {
    if (isFull(q)) {
        return -1;
    }
    q->que[q->rear++] = x;
    return 0;
}

int deque (struct charQueue* q) {
    int i;
    if (isEmpty(q))
        return -1;
    q->rear--;
    for (i = 0; i < q->rear; i++) {
        q->que[i] = q->que[i + 1];
    }
    return 0;
}

int peek (struct charQueue* q, char* x) {
    if (isEmpty(q)) {
        return - 1;
    }
    *x = q->que[q->front];
    return 0;
}

int capacity (struct charQueue* q) {
    return q->max;
}

int size (struct charQueue *q) {
    return q->rear;
}

int isEmpty (struct charQueue *q) {
    return q->rear <= 0;
}

int isFull (struct charQueue *q) {
    return q->rear >= q->max;
}

void print (struct charQueue* q) {
    int i;
    if (isEmpty(q)) {
        printf("[ERROR : Queue is Empty]\n");
        return;
    }
    printf("[");
    for (i = 0; i < q->rear - 1; i++) {
        printf("%c ", q->que[i]);
    }
    printf("%c]", q->que[q->rear - 1]);
    printf("\n");
}

void terminate (struct charQueue *q) {
    if (q->que != NULL)
        free(q->que);
    q->max = 0;
    q->rear = 0;
}