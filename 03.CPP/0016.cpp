#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int bestSum = 0;
        int bestDiff = std::numeric_limits<int>::max();

        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];
                int currDiff = abs(currSum - target);

                if (currDiff < bestDiff) {
                    bestDiff = currDiff;
                    bestSum = currSum;
                }

                if (currSum < target) {
                    left++;
                } else if (currSum > target) {
                    right--;
                } else {
                    return currSum;
                }
            }
        }

        return bestSum;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = sol.threeSumClosest(nums, target);
    
    std::cout << "Result: " << result << "\n";
    return 0;
}