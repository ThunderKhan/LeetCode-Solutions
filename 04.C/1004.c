#include <stdio.h>

int longestOnes(int* nums, int numsSize, int k) {
    int left = 0;
    int zeroCount = 0;
    int maxLen = 0;

    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            zeroCount++;
        }

        while (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }

            left++;
        }

        int currLen = right - left + 1;
        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }

    return maxLen;
}

int main() {
    int nums[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int result = longestOnes(nums, numsSize, k);
    printf("%d", result);

    return 0;
}