#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int minPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), compare);
    int left = 0;
    int right = numsSize - 1;
    int maxSum = INT_MIN;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum > maxSum) {
            maxSum = sum;
        }

        left++;
        right--;
    }

    return maxSum;
}

typedef struct {
    int nums[10];
    int size;
    int expected;
    const char* description;
} Test;

int main() {
    Test tests[] = {
        {{3,5,2,3}, 4, 7, "Given example 1"},
        {{3,5,4,2,4,6}, 6, 8, "Given example 2"},
        {{1,1}, 2, 2, "Minimum size"},
        {{1,100000}, 2, 100001, "Extreme values"},
        {{5,5,5,5}, 4, 10, "All equal"},
        {{1,2,3,4}, 4, 5, "Perfect symmetry"},
        {{1,2,3,100}, 4, 101, "One dominant large"},
        {{10,1,9,2,8,3}, 6, 11, "Random order"},
        {{1,1,1,100,100,100}, 6, 101, "Many duplicates"},
        {{2,2,2,3}, 4, 5, "Unbalanced duplicates"},
        {{7,3,5,1}, 4, 8, "Reverse order"},
        {{1,50,50,50,50,1}, 6, 100, "Heavy middle"},
        {{4,4,4,4,4,4}, 6, 8, "All identical"},
        {{1,2,2,2,9,10}, 6, 11, "Clustered values"},
        {{100000,1,99999,2}, 4, 100001, "Large boundary sums"},
    };

    int total = sizeof(tests) / sizeof(Test);
    int passed = 0;

    for (int i = 0; i < total; i++) {
        Test t = tests[i];
        int actual = minPairSum(t.nums, t.size);

        if (actual == t.expected) {
            printf("✅ PASS | Test %d: %s\n", i+1, t.description);
            passed++;
        } else {
            printf("❌ FAIL | Test %d: %s\n", i+1, t.description);
            printf("   Expected: %d, Actual: %d\n", t.expected, actual);
        }
    }

    if (passed == total)
        printf("\n🎉 All tests passed! (%d/%d)\n", passed, total);
    else
        printf("\n⚠️ %d/%d tests passed\n", passed, total);

    return 0;
}