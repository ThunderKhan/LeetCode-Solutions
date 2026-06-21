#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int low =  0;
    int high = 1;
    int uniqueCount = 1;

    while (high < numsSize) {
        if (nums[high - 1] == nums[high]) {
            high++;
            continue;
        }

        nums[low + 1] = nums[high];
        low++;
        high++;
        uniqueCount++;
    }

    return uniqueCount;
}

int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = removeDuplicates(nums, numsSize);
    printf("%d, ", result);

    printf("[");
    for (int i = 0; i < result; i++) {
        printf("%d", nums[i]);
        printf("%s", (i < result - 1 ? ", " : ""));
    }
    
    printf("]");

    return 0;
}