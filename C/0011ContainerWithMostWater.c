#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxArea(int* height, int heightSize){
    int max_area = INT_MIN;

    int left = 0;
    int right = heightSize - 1;

    while(left < right){
        int width = abs(left - right);
        int length = 0;
        if(height[left] < height[right]){
            length = height[left];
        } else{
            length = height[right];
        }

        int currArea = width * length;
        if(currArea > max_area){
            max_area = currArea;
        }

        if(height[left] < height[right]){
            left++;
        } else{
            right--;
        }
    }

    return max_area;
}

int main(){

    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);

    int result = maxArea(height, heightSize);
    printf("The maximum area in which water can be stroes is %d", result);
    
    return 0;
}