/*
by GEEE3, March 13, 2021
The eight queens puzzle is the problem of placing eight chess queens on an 8 by 8 chessboard
so that no two queens threaten each other
Thus, a solution requires that no two queens share the same row, column, or diagonal
*/

#include <stdio.h>

int rowFlag[8] = {0, };
int rDiagonalFlag[15] = {0, };
int lDiagonalFlag[15] = {0, };
int position[8] = {0, };
int count = 0;

void EQueens (int row) {
    if (row == 8) {
        count++;
        return;
    }
    
    for (int col = 0; col < 8; col++) {
        if (rowFlag[col] || rDiagonalFlag[7 + row - col] || lDiagonalFlag[row + col])
            continue;

        rowFlag[col] = 1;
        rDiagonalFlag[7 + row - col] = 1;
        lDiagonalFlag[row + col] = 1;
        EQueens(row + 1);

        rDiagonalFlag[7 + row - col] = 0;
        lDiagonalFlag[row + col] = 0;
        rowFlag[col] = 0;
    }
}

int main(int argc, const char * argv[]) {
    EQueens(0);
    printf("%d\n", count);
    return 0;
}