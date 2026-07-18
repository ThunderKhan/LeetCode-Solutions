#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxAscendingSum(int* nums, int numsSize) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            currentSum += nums[i];
        } else {
            currentSum = nums[i];
        }

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    int nums[] = {10, 20, 30, 5, 10, 50};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int result = maxAscendingSum(nums, numsSize);
    printf("%d", result);
    
    return 0;
}