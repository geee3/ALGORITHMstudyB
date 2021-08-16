/*
by GEEE3, August 16, 2021
Like the Naive Algorithm, Rabin-Karp algorithm also slides the pattern one by one
But unlike the Naive algorithm, Rabin Karp algorithm matches the hash value
of the pattern with the hash valus of current substring of text,
and if the hash values match then only it starts matching individual characters
So Rabin-Karp algorithm needs to calculate hash values for following strings

1. Pattern itself
2. All the substrings of text

Sinch we need to efficiently calculate hash values for all the substrings of text,
we must have a hash function which has the following property:
Hash at the next shift must be efficiently computable from the current hash value
Therefore, the numeric value is calculated using modular arithmetic to make sure
that the hash values can be stored in an integer variable(can fit in memory words)

To do rehashing,
we need to take off the most significant digit and add the new least significant digit
*/

#include <stdio.h>
#include <string.h>

void RabinKarpSearch(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int prime = 101;
    int textHash = 0;
    int patternHash = 0;
    int hash = 1;
    int matchFlag;

    for(int i = 0; i < patternLength - 1; i++)
        hash = (hash * 256) % prime;

    for(int i = 0; i < patternLength; i++) {
        textHash = (256 * textHash + text[i]) % prime;
        patternHash = (256 * patternHash + pattern[i]) % prime;
    }

    for(int i = 0; i <= textLength - patternLength; i++) {
        if(patternHash == textHash) {
            matchFlag = 0;
            for(int j = 0; j < patternLength; j++)
                if(text[i + j] == pattern[j])
                    matchFlag++;
            if(matchFlag == patternLength)
                printf("Pattern found at index %d\n", i);
        }

        if(i < textLength - patternLength) {
            textHash = (256 * (textHash - text[i] * hash) + text[i + patternLength]) % prime;
            if(textHash < 0)
                textHash = textHash + prime;
        }
    }
}

int main(void) {
    char *text = "AABAACAADAABAABA";
    char *pattern = "AABA";

    printf("[Rabin-Karp Algorithm]\n");
    printf("\nInput:\n");
    printf("text = %s\n", text);
    printf("pattern = %s\n", pattern);
    printf("\n");

    RabinKarpSearch(text, pattern);
    return 0;
}