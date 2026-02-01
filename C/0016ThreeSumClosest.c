#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    int x = *(const int *)a;
    int y = *(const int *)b;

    if(x < y){
        return -1;
    }
    if(x > y){
        return 1;
    }

    return 0;
}

int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), compare);

    int bestDiff = INT_MAX;
    int bestSum = 0;

    for(int i = 0; i < numsSize - 2; i++){
        int left = i + 1;
        int right = numsSize - 1;

        while(left < right){
            int currSum = nums[i] + nums[left] + nums[right];
            int currDiff = abs(currSum - target);

            if(currDiff < bestDiff){
                bestDiff = currDiff;
                bestSum = currSum;
            }

            if(currSum < target){
                left++;
            } else if(currSum > target){
                right--;
            } else{
                return currSum;
            }
        }
    }

    return bestSum;
}

int main(){

    int nums[] = {0, 0, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 1;
    printf("%d", threeSumClosest(nums, numsSize, target));

    return 0;
}