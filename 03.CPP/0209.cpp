#include <iostream>
#include <vector>
#include <limits>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int windowSum = 0;
        int minLen = std::numeric_limits<int>::max();

        for (int right = 0; right < n; right++) {
            windowSum += nums[right];

            while (windowSum >= target) {
                int currLen = right - left + 1;

                if (currLen < minLen) {
                    minLen = currLen;
                }

                windowSum -= nums[left];
                left++;
            }
        }

        if (minLen == std::numeric_limits<int>::max()) {
            return 0;
        } else {
            return minLen;
        }
    }
};

int main() {
    Solution sol;

    int target = 7;
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};

    std::cout << sol.minSubArrayLen(target, nums) << "\n";
    return 0;
}