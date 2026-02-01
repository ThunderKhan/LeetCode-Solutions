#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int threeSunSamller(vector<int>& nums, int target){
    int n = nums.size();
    int tripletCount = 0;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n - 2; i++){
        int left = i + 1;
        int right = n - 1;

        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];

            if(sum < target){
                tripletCount += (right - left);
                left += 1;
            } else{
                right -= 1;
            }
        }
    }

    return tripletCount;
}

int main(){
    vector<int> nums = {-2, 0, 1, 3};
    int target = 2;
    int result = threeSunSamller(nums, target);

    cout << result << '\n';
}