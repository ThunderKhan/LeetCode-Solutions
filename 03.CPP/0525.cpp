#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findMaxLength(std::vector<int> nums) {
        std::unordered_map<int, int> map;
        map[0] = -1;

        int runningSum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                runningSum -= 1;
            } else {
                runningSum += 1;
            }

            if (map.find(runningSum) != map.end()) {
                int currLen = i - map[runningSum];
                maxLen = std::max(maxLen, currLen);
            } else {
                map[runningSum] = i;
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {0, 1, 1, 1, 1, 1, 0, 0, 0};
    int result = sol.findMaxLength(nums);

    std::cout << result << "\n";
    return 0;
}