#include <stdio.h>
#include <stdbool.h>

int findDuplicate(int* nums){
    int slow = nums[0];
    int fast = nums[0];

    while(true){
        slow = nums[slow];
        fast = nums[nums[fast]];

        if(slow == fast){
            break;
        }
    }

    slow = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main(){

    int nums[] = {1, 3, 4, 2, 2};
    int result = findDuplicate(nums);

    printf("The duplicate number is: %d", result);

    return 0;
}