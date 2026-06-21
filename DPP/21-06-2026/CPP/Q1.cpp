#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

class Solution {
public:
    int closestPairToTarget(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int minDiff = INT_MAX;

        while (left < right) {
            int currentSum = nums[left] + nums[right];
            int absDiff = std::abs(currentSum - target);

            if (absDiff < minDiff) {
                minDiff = absDiff;
            }

            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                break;
            }
        }

        return minDiff;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {1, 3, 5, 8, 12};
    int target = 10;
    int result = sol.closestPairToTarget(nums, target);

    std::cout << result << std::endl;

    return 0;
}