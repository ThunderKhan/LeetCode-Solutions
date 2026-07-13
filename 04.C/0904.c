#include <stdio.h>
#include <stdlib.h>

int totalFruit(int* fruits, int fruitsSize)  {
    int* count = calloc(fruitsSize, sizeof(int));

    int left = 0;
    int distinct = 0;
    int maxLen = 0;

    for (int right = 0; right < fruitsSize; right++) {

        if (count[fruits[right]] == 0) {
            distinct++;
        }

        count[fruits[right]]++;

        while (distinct > 2) {

            count[fruits[left]]--;

            if (count[fruits[left]] == 0) {
                distinct--;
            }

            left++;

        }

        int currLen = right - left + 1;
        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }

    free(count);
    return maxLen;
}

int main() {
    int fruits[] = {1, 2, 3, 2, 2};
    int fruitsSize = sizeof(fruits) / sizeof(fruits[0]);

    printf("%d", totalFruit(fruits, fruitsSize));
    return 0;
}