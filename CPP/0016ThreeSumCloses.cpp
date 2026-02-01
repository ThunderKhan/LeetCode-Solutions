#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target){
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int bestDiff = INT_MAX;
    int bestSum = 0;

    for(int i = 0; i < n - 2; i++){
        int left = i + 1;
        int right = n - 1;

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
    vector<int> nums = {0, 0, 0};
    int target = 1;

    cout << threeSumClosest(nums, target);
}