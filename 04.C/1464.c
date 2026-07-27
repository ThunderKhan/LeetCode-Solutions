#include <stdio.h>

int maxProduct(int* nums, int numsSize) {
    int max1 = 0, max2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max1) {
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] > max2) {
            max2 = nums[i];
        }
    }

    return ((max1 - 1) * (max2 - 1));
}

int main() {
    int nums[] = {2, 3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maxProduct(nums, numsSize);
    printf("%d", result);

    return 0;
}