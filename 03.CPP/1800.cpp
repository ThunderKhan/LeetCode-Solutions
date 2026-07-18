#include <iostream>
#include <vector>

class Solution {
public:
    int maxAscendingSum(std::vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            } else {
                currentSum = nums[i];
            }

            maxSum = std::max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {10, 20, 30, 5, 10, 50};
    int result = sol.maxAscendingSum(nums);

    std::cout << result << "\n";
    return 0;
}