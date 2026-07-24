int findMiddleIndex(int* nums, int numsSize) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    int left = 0;
    for (int i = 0; i < numsSize; i++) {
        int right = totalSum - left - nums[i];

        if (right == left) {
            return i;
        }

        left += nums[i];
    }

    return -1;
}