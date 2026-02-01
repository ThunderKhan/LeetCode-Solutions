#include <stdio.h>

int dominantIndex(int* nums, int numsSize){
    int largest = nums[0];
    int largestIdx = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > largest){
            largest = nums[i];
            largestIdx = i;
        }
    }

    for(int i = 0; i < numsSize; i++){
        if(nums[i] == largest){
            continue;
        }

        if((2 * nums[i]) > largest){
            return -1;
        }
    }

    return largestIdx;
}

int main(){

    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = dominantIndex(nums, numsSize);

    printf("%d", result);
    return 0;
}