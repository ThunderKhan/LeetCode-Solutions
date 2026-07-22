#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int* nums, int numsSize) {
    int localMax = nums[0];
    int globalMax = nums[0];
    
    int localMin = nums[0];
    int globalMin = nums[0];

    int totalSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        localMax = max(nums[i], nums[i] + localMax);
        globalMax = max(localMax, globalMax);
        
        localMin = min(nums[i], nums[i] + localMin);
        globalMin = min(localMin, globalMin);

        totalSum += nums[i];
    }

    if (totalSum == globalMin) {
        return globalMax;
    }

    int wrappingSum = totalSum - globalMin;
    int result = max(globalMax, wrappingSum);

    return result;
}