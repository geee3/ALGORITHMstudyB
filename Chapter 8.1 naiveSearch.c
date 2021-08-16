/*
by GEEE3, August 16, 2021
Pattern searching is an important problem in computer science
When we do search for a string in notepad/word file or browser or database,
pattern searching algorithms are used to show the search results

Naive Pattern Searching:
Slide the pattern over text one by one and check for a match
If a match is found, then slides by 1 again to check for subsequent matches
*/

#include <stdio.h>
#include <string.h>

void naiveSearch(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int matchFlag;

    printf("Output:\n");

    for(int i = 0; i <textLength; i++) {
        matchFlag = 0;
        for(int j = 0; j < patternLength; j++) {
            if(text[i + j] ==  pattern[j])
            matchFlag++;
        }
        if(matchFlag == patternLength)
            printf("Pattern found at index %d\n", i);
    }
}

int main(void) {
    char *text = "AABAACAADAABAABA";
    char *pattern = "AABA";

    printf("[Naive Algorithm]\n");
    printf("\nInput:\n");
    printf("text = %s\n", text);
    printf("pattern = %s\n", pattern);
    printf("\n");

    naiveSearch(text, pattern);
    return 0;
}