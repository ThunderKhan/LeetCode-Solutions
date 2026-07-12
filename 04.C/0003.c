#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int lastSeen[256];

    for (int i = 0; i < 256; i++) {
        lastSeen[i] = -1;
    }

    int left = 0;
    int maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        char current = s[right];

        if (lastSeen[current] >= left) {
            left = lastSeen[current] + 1;
        }

        lastSeen[current] = right;

        int currLen = right - left + 1;
        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }

    return maxLen;
}

int main() {
    char s[] = "abcabcbb";

    printf("%d", lengthOfLongestSubstring(s));
    return 0;
}