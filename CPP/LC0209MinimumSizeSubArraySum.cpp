#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int minSubArrayLen(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int windowSum = 0;
    int minLen = numeric_limits<int>::max();

    for (int high = 0; high < n; high++) {
        windowSum += nums[high];

        while (windowSum >= target) {
            int length = high - low + 1;
            if (length < minLen) {
                minLen = length;
            }
            windowSum -= nums[low];
            low++;
        }
    }

    if (minLen == numeric_limits<int>::max()) {
        return 0;
    } else {
        return minLen;
    }
}

int main() {

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int result = minSubArrayLen(nums, target);
    cout << result << endl;
    return 0;
}