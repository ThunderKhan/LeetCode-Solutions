#include <stdio.h>
#include <limits.h>

int minSubArrayLen(int* nums, int numsSize, int target) {
    int low = 0;
    int windowSum = 0;
    int minLen = INT_MAX;

    for (int high = 0; high < numsSize; high++) {
        windowSum += nums[high];

        while (windowSum >= target) {
            int length = high - low + 1;
            if (length < minLen) {
                minLen = length;
            }
            windowSum -= nums[low];
            low++;
        }
    }

    if (minLen == INT_MAX) {
        return 0;
    } else {
        return minLen;
    }
}

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 7;

    int result = minSubArrayLen(nums, numsSize, target);
    printf("%d", result);
    return 0;
}