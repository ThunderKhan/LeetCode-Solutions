#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    if (numsSize == 0) {
        return NULL;
    }

    int* ans = malloc(numsSize * sizeof(int));

    if (ans == NULL) {
        *returnSize = 0;
        return NULL;
    }

    ans[0] = nums[0];

    for (int i = 1; i < numsSize; i++) {
        ans[i] = ans[i - 1] + nums[i];
    }

    return ans;
}

void printArray(int* nums, int numsSize) {
    printf("[");
    
    for (int i = 0; i < numsSize; i++) {
        printf("%d", nums[i]);

        if (i < numsSize - 1) {
            printf(", ");
        }
    }

    printf("]");
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = runningSum(nums, numsSize, &returnSize);
    
    if (result == NULL && returnSize > 0) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printArray(result, returnSize);

    free(result);
    return 0;
}