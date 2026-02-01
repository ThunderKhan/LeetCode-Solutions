#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int twoSumLessThanK(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    int maxSum = numeric_limits<int>::min();

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int currSum = nums[left] + nums[right];
        if (currSum < k) {
            if (currSum > maxSum) {
                maxSum = currSum;
            }
            left++;
        } else {
            right--;
        }
    }

    return maxSum;
}

int main() {

    vector<int> nums = {34, 23, 1, 24, 75, 33, 54, 8};
    int k = 60;

    int result = twoSumLessThanK(nums, k);
    cout << "The maximum sum less than k in the array is: " << result << endl;
    return 0;
}