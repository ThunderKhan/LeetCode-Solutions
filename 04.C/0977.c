#include <stdio.h>
#include <stdlib.h>

int* sortedSqures(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));

    int left = 0;
    int right = numsSize - 1;
    int write = numsSize - 1;

    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[write] = nums[left] * nums[left];
            left++;
        } else {
            result[write] = nums[right] * nums[right];
            right--;
        }

        write--;
    }

    return result;
}

void printArray(int* arr, int arrSize) {
    printf("[");
    for (int i = 0; i < arrSize; i++) {
        printf("%d", arr[i]);

        if (i < arrSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int nums[] = {-7, -3, 2, 3, 11,};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = sortedSqures(nums, numsSize, &returnSize);
    printArray(result, returnSize);

    free(result);
    return 0;
}