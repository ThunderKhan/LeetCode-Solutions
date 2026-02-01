#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b){
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int twoSumLessThanK(int* nums, int numsSize, int k){
    int maxSum = INT_MIN;
    qsort(nums, numsSize, sizeof(int), compare);

    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int currSum = nums[left] + nums[right];
        if (currSum < k) {
            if (currSum > maxSum) {
                maxSum = currSum;
            }
            left++;
        } else {
            right--;
        }
    }

    if (maxSum == INT_MIN) return -1;
    return maxSum;
}

int main() {
    
    int nums[] = {34, 23, 1, 24, 75, 33, 54, 8};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 60;

    int result = twoSumLessThanK(nums, numsSize, k);
    printf("The maximum sum less than k in the array is: %d", result);
    return 0;
}