#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxProduct(int* nums, int numsSize) {
    int maxProductEndingHere = nums[0];
    int minProductEndingHere = nums[0];
    int maximumProduct = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int current = nums[i];

        int prevMax = maxProductEndingHere;
        int prevMin = minProductEndingHere;

        maxProductEndingHere = max(
            current,
            max(
                current * prevMax,
                current * prevMin
            )
        );

        minProductEndingHere = min(
            current,
            min(
                current * prevMax,
                current * prevMin
            )
        );

        maximumProduct = max(maximumProduct, maxProductEndingHere);
    }

    return maximumProduct;
}

int main() {
    int nums[] = {2, 3, -2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maxProduct(nums, numsSize);

    printf("%d", result);
    return 0;
}