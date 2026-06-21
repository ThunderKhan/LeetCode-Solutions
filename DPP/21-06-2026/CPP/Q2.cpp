#include <iostream>
#include <vector>

class Solution {
public:
    int numberOfSmallerPairs(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        int count = 0;

        while (left < right) {
            int currentSum  = nums[left] + nums[right];

            if (currentSum < target) {
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {1, 2, 3, 4};
    int target = 6;
    
    int result = sol.numberOfSmallerPairs(nums, target);
    
    std::cout << result << std::endl;
    return 0;
}