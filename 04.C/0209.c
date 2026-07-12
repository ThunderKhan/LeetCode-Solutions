#include <stdio.h>
#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int windowSum = 0;
    int minLen  = INT_MAX;

    for (int right = 0; right < numsSize; right++) {
        windowSum += nums[right];

        while (windowSum >= target) {
            int currLen = right - left + 1;
            
            if  (currLen < minLen) {
                minLen = currLen;
            }
            
            if (currLen < minLen) {
                minLen = currLen;
            }

            windowSum -= nums[left];
            left++;
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

    printf("%d", minSubArrayLen(target, nums, numsSize));
    return 0;
}