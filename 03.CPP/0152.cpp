#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int> nums) {
        int maxProductEndingHere = nums[0];
        int minProductEndingHere = nums[0];
        int maximumProduct = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int current = nums[i];

            int prevMax = maxProductEndingHere;
            int prevMin = minProductEndingHere;

            maxProductEndingHere = std::max(
                current,
                std::max(prevMax * current,
                prevMin * current)
            );
            
            minProductEndingHere = std::min(
                current,
                std::min(prevMax * current,
                prevMin * current)
            );

            maximumProduct = std::max(maximumProduct, maxProductEndingHere);
        }

        return maximumProduct;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums = {2, 3, -2, 4};
    int result = sol.maxProduct(nums);

    std::cout << result << "\n";
    return 0;
}