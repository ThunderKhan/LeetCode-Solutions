#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        int n = nums.size();

        std::vector<int> ans(n);
        ans[0] = nums[0];

        for (auto i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + nums[i];
        }

        return ans;
    }
};

void printVector(std::vector<int>& arr) {
    std::cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];

        if (i < arr.size() - 1 ) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

int main() {
    Solution sol;

    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> ans = sol.runningSum(nums);

    printVector(ans);
    return 0;
}