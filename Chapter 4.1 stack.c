/*
by GEEE3, March 3, 2021
In computer science, a stack is an abstract data type that serves as a collection of elements,
with two main principal oerations:
1. Push, which adds an element to the collection
2. Pop which removes the most recently added element that was not yet removed
The order in which elements come off a stack gives rise to its alternative name, LIFO
Additionly, a peek operation may give access to the top without modifying the stack
This structure makes it easy to take an item off the top of the stack,
while getting to an item deeper in the stack may require taking off multiple other items first
*/

#include <stdio.h>
#include <stdlib.h>

/* stack that implements the stack */
struct charStack {
    int max; /* volume of stack */
    int ptr; /* stack pointer */
    char* stk; /* point of first element */
};

/* initialize stack */
struct charStack* initialize (int max);

/* push data in stack */
int push (struct charStack* s, char x);

/* pop data from stack */
int pop (struct charStack* s);

/* peek data from stack */
int peek (struct charStack* s, char* x);

/* return maximum capacity of stack */
int capacity (struct charStack* s);

/* return the number of data in stack */
int size (struct charStack* s);

/* is the stack empty? */
int isEmpty (struct charStack* s);

/* is the stack full? */
int isFull (struct charStack* s);

/* print all data in stack */
void print (struct charStack* s);

/* stack termination */
void terminate (struct charStack* s);

int main (void) {
    int max, menu = 1;
    char x;
    printf("Enter the capacity of the stack : ");
    scanf("%d", &max);
    struct charStack* s = initialize(max);
    printf("Please enter the action to be performed\n");

    while (menu != 0) {
        printf("1. push 2. pop 3. capacity 4. peek 5. print 0. terminate : ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("[Alphabet to Push] : ");
                scanf(" %c", &x);
                if(push(s, x) == -1)
                    printf("[ERROR : Stack is Full]\n");
                break;
            case 2:
                if(pop(s) == -1) {
                    printf("[ERROR : Stack is Empty]\n");
                    break;
                }
                printf("[Data Popped]\n");
                break;
            case 3:
                printf("[Stack Capacity] : %d / %d\n", size(s), capacity(s));
                break;
            case 4:
                if(peek(s, &x) == -1) {
                    printf("[ERROR : Stack is Empty]\n");
                    break;
                }
                printf("[Data at the Top is] : %c\n", x);
                break;
            case 5:
                print(s);
                break;
            default:
                break; 
        }
    }
}

struct charStack* initialize (int max) {
    struct charStack* s = (struct charStack*)malloc(sizeof(struct charStack));
    s->ptr = 0;
    s->max = max;
    s->stk = (char*)malloc(s->max * sizeof(char));
    return s;
}

int push (struct charStack* s, char x) {
    if (isFull(s)) {
        return -1;
    }
    s->stk[s->ptr++] = x;
    return 0;
}

int pop (struct charStack* s) {
    if (isEmpty(s))
        return -1;
    s->ptr--;
    return 0;
}

int peek (struct charStack* s, char* x) {
    if (isEmpty(s)) {
        return - 1;
    }
    *x = s->stk[s->ptr - 1];
    return 0;
}

int capacity (struct charStack* s) {
    return s->max;
}

int size (struct charStack *s) {
    return s->ptr;
}

int isEmpty (struct charStack *s) {
    return s->ptr <= 0;
}

int isFull (struct charStack *s) {
    return s->ptr >= s->max;
}

void print (struct charStack* s) {
    int i;
    if (isEmpty(s)) {
        printf("[ERROR : Stack is Empty]\n");
        return;
    }
    printf("[");
    for (i = 0; i < s->ptr - 1; i++) {
        printf("%c ", s->stk[i]);
    }
    printf("%c]", s->stk[s->ptr - 1]);
    printf("\n");
}

void terminate (struct charStack *s) {
    if (s->stk != NULL)
        free(s->stk);
    s->max = 0;
    s->ptr = 0;
}