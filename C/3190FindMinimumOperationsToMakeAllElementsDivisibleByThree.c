#include <stdio.h>

int minimumOperations(int* nums, int numsSize){
    int counter = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] % 3 != 0){
            int k = nums[i] % 3;
            if(3 - k > k){
                counter += k;
            }else{
                counter += (3 - k);
            }
        }
    }

    return counter;
}

int main(){

    int nums[] = {1, 2, 3, 4};
    int numsSize = 4;
    printf("%d", minimumOperations(nums, numsSize));

    return 0;
}