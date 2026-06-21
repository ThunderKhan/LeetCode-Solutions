#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int low = 0;
        int high = 1;
        int uniqueCount = 1;
        int n = nums.size();

        while (high < n) {
            if (nums[high - 1] == nums[high]) {
                high++;
                continue;
            }

            nums[low + 1] = nums[high];
            high++;
            low++;
            uniqueCount++;
        }

        return uniqueCount;
    }
};

int main() {
    Solution sol;
    
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int result = sol.removeDuplicates(nums);
    std::cout << "Test 1: " << result << ", [";
    for (int i = 0; i < result; i++) {
        std::cout << nums[i] << (i < result - 1 ? ", " : "");
    }
    std::cout << "]" << std::endl;

    return 0;
}