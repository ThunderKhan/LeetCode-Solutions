#include <stdio.h>
#include <string.h>

int finalValueAfterOperations(char **operations, int operationsSize) {
    int finalValue = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (strcmp(operations[i], "--X") == 0 ||
            strcmp(operations[i], "X--") == 0) {
            finalValue--;
        } else {
            finalValue++;
        }
    }

    return finalValue;
}

int main() {
    char *operations[] = {"--X", "X++", "X++"};
    int operationsSize = 3;

    int result = finalValueAfterOperations(operations, operationsSize);

    printf("Final Value = %d\n", result);

    return 0;
}
