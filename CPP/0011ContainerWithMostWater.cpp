#include <iostream>
#include <vector>
#include <cmath>
#include <format>
#include <limits>

using namespace std;

int maxArea(vector<int>& height){
    int max_area = numeric_limits<int>::min();
    int n = height.size();

    int left = 0;
    int right = n - 1;

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
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);

    cout << "The maximum area in which water can be stored is " << result << endl;
    return 0;
}