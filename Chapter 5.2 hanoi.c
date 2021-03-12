/*
by GEEE3, March 13, 2021
The Tower of Hanoi is an mathematical game or puzzle
It consist of three rods and a nuber of disks of different sizes, which can slide onto any rod
The puzzle starts with the disks in a neat stack in ascending order of size on the rod,
the smallest at the top, thus making a conical shape
The objective of the puzzle is to move the entire stack to last rod, obeying the following simple rules:
1. Only one disk can be moved at a time
2. Each move consists of taking the upper disk from one of the stacks
and placing on the top of another stack or an empty rod
3. No larger disk may be placed on top of a smaller disk
*/

#include <stdio.h>

void hanoi (int disk, char fromRod, char toRod, char auxRod) {
    if (disk == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    hanoi(disk - 1, fromRod, auxRod, toRod);
    printf("Move disk %d from rod %c to rod %c\n", disk, fromRod, toRod);
    hanoi(disk - 1, auxRod, toRod, fromRod);
}

int main (void) {
    int disk;
    printf("Enter the number of Disks : ");
    scanf("%d", &disk);
    hanoi(disk, 'A', 'B', 'C');
    return 0;
}

