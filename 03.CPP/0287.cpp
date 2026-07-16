#include <iostream>
#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast) {
                break;
            }
        }

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {1, 3, 4, 2, 2};
    int result = sol.findDuplicate(nums);

    std::cout << result << "\n";
    return 0;
}