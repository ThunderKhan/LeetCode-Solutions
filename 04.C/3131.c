#include <stdio.h>

int min(int* nums, int numsSize) {
    int mini = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < mini) {
            mini = nums[i];
        }
    }
    return mini;
}

int addedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int x1 = min(nums1, nums1Size);
    int x2 = min(nums2, nums2Size);

    return x2 - x1;
}

int main() {
    int nums1[] = {2, 4, 6};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);

    int nums2[] = {9, 7, 5};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    printf("%d", addedInteger(nums1, nums1Size, nums2, nums2Size));
    return 0;
}