#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

char* minWindow(char* s, char* t) {

    int need[128] = {0};

    for (int i = 0; t[i] != '\0'; i++) {
        need[(int)t[i]]++;
    }

    int required = strlen(t);

    int left = 0;
    int start = 0;
    int minLen = INT_MAX;

    for (int right = 0; s[right] != '\0'; right++) {

        if (need[(int)s[right]] > 0) {
            required--;
        }

        need[(int)s[right]]--;


        while (required == 0) {

            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }


            need[(int)s[left]]++;

            if (need[(int)s[left]] > 0) {
                required++;
            }

            left++;
        }
    }


    if (minLen == INT_MAX) {
        return "";
    }


    char* answer = malloc((minLen + 1) * sizeof(char));

    strncpy(answer, s + start, minLen);

    answer[minLen] = '\0';

    return answer;
}

int main() {
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";

    char* result = minWindow(s, t);
    
    printf("%s", result);
    free(result);
    return 0;
}