#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);

    int bestSum = 0;
    int bestDiff = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int currSum = nums[i] + nums[left] + nums[right];
            int currDiff = abs(currSum - target);

            if (currDiff < bestDiff) {
                bestDiff = currDiff;
                bestSum = currSum;
            }

            if (currSum < target) {
                left++;
            } else if (currSum > target) {
                right--;
            } else {
                return currSum;
            }
        }
    }

    return bestSum;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 2;
    int result = threeSumClosest(nums, numsSize, target);

    printf("%d", result);
    return 0;
}