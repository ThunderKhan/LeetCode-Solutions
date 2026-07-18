#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSubArray(int* nums, int numsSize) {
    int bestLocalSum = nums[0];
    int bestGlobalSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        bestLocalSum = max(nums[i], nums[i] + bestLocalSum);
        bestGlobalSum =  max(bestGlobalSum, bestLocalSum);
    }

    return bestGlobalSum;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maxSubArray(nums, numsSize);
    printf("%d", result);
    
    return 0;
}