#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        map[0] = 1;

        int count = 0;
        int runningSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            int diff = runningSum - k;

            if (map.find(diff) != map.end()) {
                count += map[diff];
            }

            map[runningSum]++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {1, 1, 1};
    int k = 2;

    int result = sol.subarraySum(nums, k);
    std::cout << result << "\n";

    return 0;
}