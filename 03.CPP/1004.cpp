#include <iostream>
#include <vector>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                
                left++;
            }

            int currLen = right - left + 1;
            maxLen = std::max(maxLen, currLen);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    int result = sol.longestOnes(nums, k);
    std::cout << result << "\n";

    return 0;
}