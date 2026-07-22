#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int localMax = nums[0];
        int globalMax = nums[0];

        int localMin = nums[0];
        int globalMin = nums[0];

        int totalSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            localMax = std::max(nums[i], nums[i] + localMax);
            globalMax = std::max(localMax, globalMax);

            localMin = std::min(nums[i], nums[i] + localMin);
            globalMin = std::min(localMin, globalMin);

            totalSum += nums[i];
        }

        if (totalSum == globalMin) {
            return globalMax;
        }

        int wrappingSum = totalSum - globalMin;
        int result = std::max(globalMax, wrappingSum);

        return result;
    }
};