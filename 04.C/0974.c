#include <stdio.h>
#include <stdlib.h>

int subarraysDivByK(int* nums, int numsSize, int k) {
    int* remainderCount = calloc(k, sizeof(int));

    if (remainderCount == NULL) {
        return -1;
    }

    remainderCount[0] = 1;

    int runningSum = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        runningSum += nums[i];

        int remainder = runningSum % k;

        if (remainder < 0) {
            remainder += k;
        }

        count += remainderCount[remainder];
        remainderCount[remainder]++;
    }

    free(remainderCount);

    return count;
}

int main(void) {
    int nums[] = {4, 5, 0, -2, -3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 5;

    int result = subarraysDivByK(nums, numsSize, k);

    printf("%d\n", result);

    return 0;
}