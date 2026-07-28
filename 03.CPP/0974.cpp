#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k ) {
        std::unordered_map<int, int> map;
        map[0] = 1;

        int runningSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            int rem = runningSum % k;

            if (rem < 0) {
                rem += k;
            }

            count += map[rem];
            map[rem]++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = sol.subarraysDivByK(nums, k);
    std::cout << result << "\n";

    return 0;
}