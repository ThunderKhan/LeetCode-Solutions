#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minimumDifference(int* nums, int numsSize, int k) {
    if (k <= 1 || numsSize == 0) {
        return 0;
    }

    if (k > numsSize) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), compare);
    int left = 0;
    int right = k - 1;
    int minDiff = INT_MAX;

    while (right < numsSize) {
        int currDiff = nums[right] - nums[left];

        if (currDiff < minDiff) {
            minDiff = currDiff;
        }

        left++;
        right++;
    }
    if (minDiff == INT_MAX) {
        return 0;
    }
    return minDiff;
}

typedef struct {
    int nums[10];
    int size;
    int k;
    int expected;
    const char* description;
} Test;

int main() {
    Test tests[] = {
        {{90}, 1, 1, 0, "Single element"},
        {{9,4,1,7}, 4, 2, 2, "Example case"},
        {{1,5,9}, 3, 3, 8, "k equals array length"},
        {{5,5,5,5}, 4, 3, 0, "All values equal"},
        {{1,2,3,4,5}, 5, 3, 2, "Already sorted increasing"},
        {{8,1,2,2,3}, 5, 3, 1, "Duplicates present"},
        {{0,0,10,10}, 4, 2, 0, "Zeros included"},
        {{5,100,3}, 3, 1, 0, "k = 1 always zero"},
        {{1,100000,50000,50001}, 4, 2, 1, "Large numeric gap"},
        {{1,2}, 2, 2, 1, "Minimum valid size"},
        {{1,3,6,10,15}, 5, 2, 2, "Increasing gaps"},
        {{4,7,9,1,2}, 5, 4, 6, "Window selection matters"},
        {{5,5,5,5,100}, 5, 4, 0, "Outlier should be ignored"},
        {{10,1,9,2,8,3}, 6, 3, 2, "Alternating values"}
    };

    int total = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    for (int i = 0; i < total; i++) {
        int actual = minimumDifference(tests[i].nums, tests[i].size, tests[i].k);

        if (actual == tests[i].expected) {
            printf("✅ PASS | Test %d: %s\n", i+1, tests[i].description);
            passed++;
        } else {
            printf("❌ FAIL | Test %d: %s\n", i+1, tests[i].description);
            printf("   Expected: %d, Actual: %d\n",
                   tests[i].expected, actual);
        }
    }

    printf("\nSummary:\n");
    if (passed == total)
        printf("🎉 All tests passed! (%d/%d)\n", passed, total);
    else
        printf("⚠️ %d/%d tests passed\n", passed, total);

    return 0;
}