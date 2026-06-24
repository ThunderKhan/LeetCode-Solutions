#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n);

        int left = 0;
        int right = n - 1;
        int write = n - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[write] = nums[left] * nums[left];
                left++;
            } else {
                result[write] = nums[right] * nums[right];
                right--;
            }

            write--;
        }

        return result;
    }
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << (i < vec.size() - 1 ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;

    std::vector<int> nums = {-7, -3, 2, 3, 11};
    std::vector<int> result = sol.sortedSquares(nums);

    printVector(result);
    return 0;
}