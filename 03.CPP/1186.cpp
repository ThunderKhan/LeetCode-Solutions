#include <iostream>
#include <vector>

class Solution {
public:
    int maximumSum(std::vector<int>& arr) {
        int noDelSum = arr[0];
        int oneDelSum = -10000;
        int result = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int prevNoDel = noDelSum;

            noDelSum = std::max(
                arr[i],
                noDelSum + arr[i]
            );

            oneDelSum = std::max(
                prevNoDel,
                arr[i] + oneDelSum
            );

            result = std::max(
                result,
                std::max(oneDelSum, noDelSum)
            );
        }

        return result;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums1 = {1, -2, 0, 3};
    std::vector<int> nums2 = {1, -2, -2, 3};
    std::vector<int> nums3 = {-1, -1, -1, -1};

    int result1 = sol.maximumSum(nums1);
    int result2 = sol.maximumSum(nums2);
    int result3 = sol.maximumSum(nums3);

    std::cout << result1 << "\n";
    std::cout << result2 << "\n";
    std::cout << result3 << "\n";

    return 0;
}