#include <stdio.h>
#include <stdlib.h>

int findMaxLength(int *nums, int numsSize)
{
    int tableSize = 2 * numsSize + 1;
    int offset = numsSize;

    int *firstIndex = malloc(tableSize * sizeof(int));

    if (firstIndex == NULL) {
        return -1;
    }

    for (int i = 0; i < tableSize; i++) {
        firstIndex[i] = -2;
    }

    firstIndex[offset] = -1;

    int runningSum = 0;
    int maxLength = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            runningSum--;
        } else {
            runningSum++;
        }

        int tableIndex = runningSum + offset;

        if (firstIndex[tableIndex] != -2) {
            int currentLength = i - firstIndex[tableIndex];

            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        } else {
            firstIndex[tableIndex] = i;
        }
    }

    free(firstIndex);
    return maxLength;
}

int main(void)
{
    int nums[] = {0, 1, 1, 1, 1, 1, 0, 0, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = findMaxLength(nums, numsSize);

    printf("%d\n", result);  // 6
    return 0;
}