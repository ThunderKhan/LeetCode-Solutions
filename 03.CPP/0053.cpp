#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int bestLocalSum = nums[0];
        int bestGlobalSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            bestLocalSum = std::max(nums[i], nums[i] + bestLocalSum);
            bestGlobalSum = std::max(bestGlobalSum, bestLocalSum);
        }

        return bestGlobalSum;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = sol.maxSubArray(nums);

    std::cout << result << "\n";
    return 0;
}