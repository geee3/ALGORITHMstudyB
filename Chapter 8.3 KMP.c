/*
by GEEE3, August 19, 2021
The KMP matching algorithm uses degenerating property
(pattern having same sub-patterns appearing more than once in the pattern)
of the pattern and improves the worst case complexity to O(n)
The basic idea behind KMP's algorithm is:

Whenever we detect a mismatch(after some matches),
we already know some of the characters in the text of the next window
We take advantage to avoid matching the characters that will anyway match

Unlike Naive algorithm, where we slide the pattern by one and compare all characters,
we use a value from LPS[] to decide the next characters to be matched
The idea is to not match a character that we know will anyway match
*/

#include <stdio.h>
#include <string.h>

void computeLPS(char pattern[], int LPS[], int patternLength) {
    int pointer = 0, i = 1;
    LPS[0] = 0;

    while(i < patternLength) {
        if(pattern[i] == pattern[pointer])
            LPS[i++] = ++pointer;
        else {
            if(pointer != 0)
                pointer = LPS[pointer - 1];
            else
                LPS[i++] = 0;
        }
    }
}

void KMPSearch(char text[], char pattern[]) {
    int textPointer = 0, patternPointer = 0;
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int LPS[patternLength];

    computeLPS(pattern, LPS, patternLength);

    while(textPointer < textLength) {
        if(text[textPointer] == pattern[patternPointer]) {
            textPointer++;
            patternPointer++;
        }
        if(patternPointer == patternLength) {
            printf("Pattern found at index %d\n", textPointer - patternPointer);
            patternPointer = LPS[patternPointer - 1];
        }
        else if(textPointer < textLength && pattern[patternPointer] != text[textPointer]) {
            if(patternPointer != 0)
                patternPointer = LPS[patternPointer - 1];
            else
                textPointer = textPointer + 1;
        }
    }
}

int main(void) {
    char *text = "AABAACAADAABAABA";
    char *pattern = "AABA";

    printf("[KMP Algorithm for Pattern Searching]\n");
    printf("\nInput:\n");
    printf("text = %s\n", text);
    printf("pattern = %s\n", pattern);
    printf("\n");

    printf("Output:\n");
    KMPSearch(text, pattern);
    return 0;
}