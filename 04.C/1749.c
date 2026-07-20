#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxAbsoluteSum(int* nums, int numsSize) {
    int maxPosSum = nums[0];
    int maxNegSum = nums[0];
    int maxAbsSum = abs(nums[0]);

    for (int i = 1; i < numsSize; i++) {
        maxPosSum = max(nums[i], nums[i] + maxPosSum);
        maxNegSum = min(nums[i], nums[i] + maxNegSum);

        maxAbsSum = max(
            maxAbsSum,
            max(abs(maxPosSum), abs(maxNegSum))
        );
    }
}

int main() {
    int nums[] = {1, -3, 2, 3, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maxAbsoluteSum(nums, numsSize);
    printf("%d", result);
    
    return 0;
}