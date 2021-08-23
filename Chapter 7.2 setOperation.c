/*
by GEEE3, August 14, 2021
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int num;
    int *set;
} intSet;

int initialize(intSet *s, int max);
int isMember(const intSet *s, int n);
int isFull(const intSet *s);
int isEmpty(const intSet *s);
void addMember(intSet *s, int n);
void removeMember(intSet *s, int n);
void printSet(intSet *s);
void printCapacity(intSet *s);
void intersection(intSet *s1, intSet *s2, intSet *s3);
void sumOfSets(intSet *s1, intSet *s2, intSet *s3);

int main(void) {
    int endFlag = 0, setFlag, command, sizeA, sizeB, member;
    intSet A, B, C;

    printf("Program: Implement Sets In Arrays\n");
    printf("---------------------------------\n");
    printf("[Please Enter the Maximum Size of the Set A and B]\n");
    printf("Maximum Size of Set A: ");
    scanf("%d", &sizeA);
    printf("Maximum Size of Set B: ");
    scanf("%d", &sizeB);
    initialize(&A, sizeA);
    initialize(&B, sizeB);
    initialize(&C, sizeA + sizeB);
    printf("\n");

    while(endFlag == 0) {
        printf("[Please Enter Number to Execute]\n");
        printf("1. Print Set.\n");
        printf("2. Add Member.\n");
        printf("3. Delete Member.\n");
        printf("4. Print Capacity.\n");
        printf("5. Set Operation.\n");
        printf("6. Terminate.\n");
        scanf("%d", &command);
        printf("\n");

        switch(command) {
            case 1:
                printf("Set A: ");
                printSet(&A);
                printf("Set B: ");
                printSet(&B);
                printf("\n");
                break;
            case 2:
                printf("1. Add Member in Set A\n");
                printf("2. Add Member in Set B\n");
                scanf("%d", &setFlag);
                if(setFlag == 1) {
                    if(isFull(&A) == -1) {
                        printf("ERROR: Set A is Full\n");
                    }
                    else {
                        printf("Please Enter Member to Add: ");
                        scanf("%d", &member);
                        addMember(&A, member);
                        printf("\n");
                    }
                }
                else if(setFlag == 2) {
                    if(isFull(&B) == -1) {
                        printf("ERROR: Set B is Full\n");
                    }
                    else {
                        printf("Please Enter Member to Add: ");
                        scanf("%d", &member);
                        addMember(&B, member);
                        printf("\n");
                    }
                }
                printf("\n");
                break;
            case 3:
                printf("1. Delete Member in Set A\n");
                printf("2. Delete Member in Set B\n");
                scanf("%d", &setFlag);
                if(setFlag == 1) {
                    if(isEmpty(&A) == -1) {
                        printf("ERROR: Set A is Empty\n");
                    }
                    else {
                        printf("Please Enter Member to Delete: ");
                        scanf("%d", &member);
                        removeMember(&A, member);
                        printf("\n");
                    }
                }
                else if(setFlag == 2) {
                    if(isEmpty(&B) == -1) {
                        printf("ERROR: Set B is Empty\n");
                    }
                    else {
                        printf("Please Enter Member to Delete: ");
                        scanf("%d", &member);
                        removeMember(&B, member);
                        printf("\n");
                    }
                }
                printf("\n");
                break;
            case 4:
                printf("Capacity of Set A: ");
                printCapacity(&A);
                printf("Capacity of Set B: ");
                printCapacity(&B);
                printf("\n");
                break;
            case 5:
                printf("1. Calculate the intersection of A and B\n");
                printf("2. Calculate the Sum Of A and B\n");
                scanf("%d", &setFlag);
                if(setFlag == 1) {
                    intersection(&A, &B, &C);
                    printf("Result: ");
                    printSet(&C);
                }
                else if(setFlag == 2) {
                    sumOfSets(&A, &B, &C);
                    printf("Result: ");
                    printSet(&C);
                }
                initialize(&C, sizeA + sizeB);\
                printf("\n");
                break;
            case 6:
                printf("[Program Termination...]");
                endFlag = 1;
                break;
        }
    }
    return 0;
}

int initialize(intSet *s, int size) {
    s->num = 0;
    if((s->set = calloc(size, sizeof(int))) == NULL) {
        s->size = 0;
        return -1;
    }
    s->size = size;
    return 0;
}

int isMember(const intSet *s, int n) {
    for(int i = 0; i < s->num; i++)
        if(n == s->set[i])
            return i;
    return -1;
}

int isFull(const intSet *s) {
    if(s->size == s->num)
        return -1;
    return 0;
}

int isEmpty(const intSet *s) {
    if(s->num == 0)
        return -1;
    return 0;
}

void addMember(intSet *s, int n) {
    if(s->num < s->size && isMember(s, n) == -1)
        s->set[s->num++] = n;
}

void removeMember(intSet *s, int n) {
    int index;
    if((index = isMember(s, n)) != -1)
        s->set[index] = s->set[--s->num];
}

void printSet(intSet *s) {
    if(s->num == 0)
        printf("{ }\n");
    else {
        printf("{");
        for(int i = 0; i < s->num - 1; i++)
            printf("%d, ", s->set[i]);
        printf("%d}\n", s->set[s->num - 1]);
    }
}

void printCapacity(intSet *s) {
    printf("[%d/%d]\n", s->num, s->size);
}

void intersection(intSet *s1, intSet *s2, intSet *s3) {
    for(int i = 0; i < s1->num; i++) {
        if(isMember(s2, s1->set[i]) != -1)
            addMember(s3, s1->set[i]);
    }
}

void sumOfSets(intSet *s1, intSet *s2, intSet *s3) {
    for(int i = 0; i < s1->num; i++) {
        addMember(s3, s1->set[i]);
    }
    for(int i = 0; i < s2->num; i++) {
        addMember(s3, s2->set[i]);
    }
}