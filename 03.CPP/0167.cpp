#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int currentSum = numbers[left] + numbers[right];

            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                return {left + 1, right + 1};
            }
        }

        return {-1, -1};
    }
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i < vec.size() - 1 ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;

    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = sol.twoSum(nums, target);
    std::cout << "Test 1: ";
    printVector(result);
    
    return 0;
}