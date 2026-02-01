#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int low = 0;
    int high = 1;
    int uniqueCount = 1;

    while(high < numsSize){
        if(nums[high] == nums[high - 1]){
            high++;
            continue;
        }

        nums[low + 1] = nums[high];

        low++;
        high++;
        uniqueCount++;
    }

    return uniqueCount++;
}

int main(){

    int nums[] = {1, 1, 1, 2, 2, 3};
    int numsSize = 6;

    printf("%d", removeDuplicates(nums, numsSize));

    return 0;
}