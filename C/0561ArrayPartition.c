#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int result = 0;
    for (int i = 0; i < numsSize; i+=2) {
        result += nums[i];
    }
    return result;
}

int main() {
    int tests[][12] = {
        {1,4,3,2}, {6,2,6,5,1,2}, {1,2}, {1,1,1,1},
        {-1,-2,-3,-4}, {1,3,2,4}, {1000,-1000,0,0},
        {5,5,5,5,5,5}, {1,2,3,4,5,6}, {6,5,4,3,2,1},
        {1,2,2,3}, {10,20,30,40,50,60,70,80}, {0,0,0,0,0,0}, {-10,-1,-5,-3}
    };

    int sizes[] = {4,6,2,4,4,4,4,6,6,6,4,8,6,4};
    int expected[] = {4,9,1,2,-4,4,0,15,9,9,3,160,0,-8};

    int passed = 0;

    for (int i=0; i<14; i++) {
        int actual = arrayPairSum(tests[i], sizes[i]);
        if (actual == expected[i]) {
            printf("✅ PASS | Test %d\n", i+1);
            passed++;
        } else {
            printf("❌ FAIL | Test %d\n", i+1);
            printf("   Expected: %d, Actual: %d\n", expected[i], actual);
        }
    }

    printf("\nSummary:\n");
    if (passed == 14)
        printf("🎉 All tests passed! (%d/14)\n", passed);
    else
        printf("⚠️ %d/14 tests passed\n", passed);

    return 0;
}
