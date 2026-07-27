#include <iostream>
#include <vector>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] > max2) {
                max2 = nums[i];
            }
        }

        return ((max1 - 1) * (max2 - 1));
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {2, 3, 4, 5};
    int result = sol.maxProduct(nums);

    std::cout << result << "\n";
    return 0;
}