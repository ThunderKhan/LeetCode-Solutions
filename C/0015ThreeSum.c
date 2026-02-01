#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;

    return (x > y) - (x < y);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int capacity = 16;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 0; i < numsSize - 2; i++){
        if(nums[i] > 0){
            break;
        }

        if((i > 0) && nums[i] == nums[i - 1]){
            continue;
        }

        int left = i + 1;
        int right = numsSize - 1;

        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];

            if(sum > 0){
                right--;
            } else if(sum < 0){
                left++;
            } else{
                int* triplet = (int*) malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];

                if (*returnSize >= capacity){
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                left++;
                right--;

                while((left < right) && (nums[left] == nums[left - 1])){
                    left++;
                }

                while((left < right) && (nums[right] == nums[right + 1])){
                    right--;
                }
            }
        }
    }

    return result;
}

int main(){

    int nums[] = {-1, 0, 1, 2, -1, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;

    int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("[");
    for(int i = 0; i < returnSize; i++){
        printf("[%d, %d, %d]", result[i][0], result[i][1], result[i][2]);
        if(i < returnSize - 1){
            printf(", ");
        }
    }
    printf("]\n");

    for(int i = 0; i < returnSize; i++){
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}