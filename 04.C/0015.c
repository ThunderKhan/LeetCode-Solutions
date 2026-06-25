int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int capacity = 16;

    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < (numsSize - 2); i++) {
        if (nums[i] > 0) {
            break;
        }

        if ((i > 0) && (nums[i] == nums[i - 1])) {
            continue;
        }

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int currSum = nums[i] + nums[left] + nums[right];

            if (currSum < 0) {
                left++;
            } else if (currSum > 0) {
                right--;
            } else {
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int**)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                int* triplet = (int*)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];

                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                left++;
                right--;

                while ((left < right) && (nums[left] == nums[left - 1])) {
                    left++;
                }

                while ((left < right) && (nums[right] == nums[right + 1])) {
                    right--;
                }
            }
        }
    }

    return result;
}