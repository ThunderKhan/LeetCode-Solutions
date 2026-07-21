#include <stdio.h>
#include <stdbool.h>

bool canReach(int* start, int startSize, int* target, int targetSize) {
    int startParity = (start[0] + start[1]) % 2;
    int targetParity = (target[0] + target[1]) % 2;

    return ((startParity == targetParity) ? true : false);
}

int main() {
    int start[] = {1, 1};
    int startSize = sizeof(start) / sizeof(start[0]);

    int target[] = {1, 1};
    int targetSize = sizeof(target) / sizeof(target[0]);

    bool result = canReach(start, startSize, target, targetSize);
    
    if (result) {
        printf("true");
    } else {
        printf("false");
    }
    
    return 0;
}