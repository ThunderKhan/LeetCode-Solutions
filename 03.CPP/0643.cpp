#include <iostream>
#include <vector>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int n = nums.size();

        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;
        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i - k];

            if (windowSum > maxSum) {
                maxSum = windowSum;
            }
        }

        double maxAvg = (double) maxSum / k;
        return maxAvg;
    }
};

int main() {
    Solution sol;
    
    std::vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double result = sol.findMaxAverage(nums, k);

    std::cout << "Result: " << result << "\n";
    return 0;
}