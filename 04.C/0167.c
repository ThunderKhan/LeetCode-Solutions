#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));

    int left = 0;
    int right = numbersSize - 1;

    while (left < right) {
        int result_sum = numbers[left] + numbers[right];

        if (result_sum < target) {
            left++;
        } else if (result_sum > target) {
            right--;
        } else {
            result[0] = left + 1;
            result[1] = right + 1;
            *returnSize = 2;
            return result;
        }
    }

    result[0] = -1;
    result[1] = -1;
    *returnSize = 2;
    return result;
}

int main() {
    int numbers[] = {2, 7, 11, 15};
    int target = 9;

    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
    int returnSize = 0;

    int* result = twoSum(numbers, numbersSize, target, &returnSize);

    if (returnSize > 0) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
    }

    free(result);
    return 0;
}