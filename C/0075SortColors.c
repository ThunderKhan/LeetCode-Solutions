#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(const int* arr, size_t arrSize){
    printf("[");
    for(int i = 0; i < arrSize; i++){
        printf("%d", arr[i]);
        if(i != arrSize - 1){
            printf(", ");
        }
    }
    printf("]\n");
}

void sortColor(int* nums, int numsSize){
    int low = 0;
    int mid = 0;
    int high = numsSize - 1;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(&nums[mid], &nums[low]);
            mid++;
            low++;
        } else if(nums[mid] == 1){
            mid++;
        } else{
            swap(&nums[mid], &nums[high]);
            high--;
        }
    }
}

int main(){

    int nums[] = {2, 0, 2, 1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    sortColor(nums, numsSize);
    printArray(nums, numsSize);

    return 0;
}