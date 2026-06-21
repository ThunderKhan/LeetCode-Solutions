#include <stdio.h>

int numberOfSmallerPairs(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    int count = 0;

    while (left < right) {
        int currentSum = nums[left] + nums[right];

        if (currentSum < target) {
            count += (right - left);
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int target = 6;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = numberOfSmallerPairs(nums, numsSize, target);
    
    printf("%d", result);
    return 0;
}