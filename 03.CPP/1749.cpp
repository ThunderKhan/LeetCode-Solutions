#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

class Solution {
public:
    int maxAbosoluteSum(std::vector<int>& nums) {
        int maxPosSum = nums[0];
        int maxNegSum = nums[0];
        int maxAbsSum = std::abs(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            maxPosSum = std::max(nums[i], nums[i] + maxPosSum);
            maxNegSum = std::min(nums[i], nums[i] + maxNegSum);
            
            maxAbsSum = std::max(
                { maxAbsSum, std::abs(maxPosSum), std::abs(maxNegSum) }
            );
        }

        return maxAbsSum;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {1, -3, 2, 3, -4};
    int result = sol.maxAbsoluteSum(nums);

    std::cout << result << "\n";
    return 0;
}