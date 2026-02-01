#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    if (k > numsSize) {
        return -1.0f;
    }

    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    int maxSum = windowSum;
    for (int i = k; i < numsSize; i++) {
        windowSum += nums[i] - nums[i - k];

        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    double maxAvg = (double) maxSum / k;
    return maxAvg;
}

int main() {

    int nums[] = {1, 12, -5, -6, 50, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 4;

    double result = findMaxAverage(nums, numsSize, k);
    printf("The maximum average of a sub-array of size %d is: %.2f", k, result);
    return 0;
}