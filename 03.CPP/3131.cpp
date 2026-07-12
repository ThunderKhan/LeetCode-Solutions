#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int min(std::vector<int> nums) {
        int mini = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < mini) {
                mini = nums[i];
            }
        }
        
        return mini;
    }

    int addedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {
        int x1 = min(nums1);
        int x2 = min(nums2);

        return x2 - x1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {2, 4, 6};
    std::vector<int> nums2 = {9, 7, 5};

    std::cout << sol.addedInteger(nums1, nums2) << "\n";
    return 0;
}