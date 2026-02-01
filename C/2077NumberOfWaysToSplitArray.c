#include <stdio.h>

int waysToSplitArray(int* nums, int numsSize){
    long long totalSum = 0;
    for(int i = 0; i < numsSize; i++){
        totalSum += nums[i];
    }

    int splitCount = 0;
    long long leftSum = 0;
    for(int i = 0; i < numsSize - 1; i++){
        leftSum += nums[i];
        long long rightSum = totalSum - leftSum;

        if(leftSum >= rightSum){
            splitCount++;
        }
    }

    return splitCount;
}

int main(){
    
    int nums[] = {2, 3, 1, 0};
    int numsSize = 4;
    printf("%d", waysToSplitArray(nums, numsSize));

    return 0;
}