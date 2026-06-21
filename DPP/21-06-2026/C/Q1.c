#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int closestPairToTarget(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    int minDiff = INT_MAX;

    while (left < right) {
        int currentSum = nums[left] + nums[right];
        int absDiff = abs(currentSum - target);

        if (absDiff < minDiff) {
            minDiff = absDiff;
        }

        if (currentSum < target) {
            left++;
        } else if (currentSum > target) {
            right--;
        } else {
            break;
        }
    }

    return minDiff;
}

int main() {
    int nums[] = {1, 3, 5, 8, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 10;

    int result = closestPairToTarget(nums, numsSize, target);

    printf("%d", result);
    return 0;
}