#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;

        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < (n - 2); i++) {
            if (nums[i] > 0) {
                break;
            }

            if ((i > 0) && (nums[i] == nums[i - 1])) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];

                if (currSum < 0) {
                    left++;
                } else if (currSum > 0) {
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    while ((left < right) && (nums[left] == nums[left - 1])) {
                        left++;
                    }

                    while ((left < right) && (nums[right] == nums[right + 1])) {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};

void printVector(const std::vector<std::vector<int>>& vec) {
    std::cout << "[";

    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << "[";

        for (size_t j = 0; j < vec[i].size(); j++) {
            std::cout << vec[i][j];

            if (j < vec[i].size() - 1) {
                std::cout << ", ";
            }
        }

        std::cout << "]";

        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}

int main() {
    Solution sol;

    std::vector<int> nums = {-1, 0, 1, 2, -1, 4};
    std::vector<std::vector<int>> result = sol.threeSum(nums);

    printVector(result);
    return 0;
}