#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findWordsContaining(char **words, int wordsSize, char x, int *returnSize) {
    int capacity = 10;
    int *ans = malloc(capacity * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < wordsSize; i++) {
        if (strchr(words[i], x) != NULL) {
            if (*returnSize >= capacity) {
                capacity *= 2;
                ans = realloc(ans, capacity * sizeof(int));
            }
            ans[*returnSize] = i;
            (*returnSize)++;
        }
    }

    return ans;
}

int main() {
    char *words[] = {"apple", "banana", "cherry", "date"};
    int wordsSize = 4;
    char x = 'a';
    int returnSize;

    int *indices = findWordsContaining(words, wordsSize, x, &returnSize);

    printf("Words containing '%c' are at indices: ", x);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");

    free(indices);
    return 0;
}