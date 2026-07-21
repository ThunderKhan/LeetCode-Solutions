#include <iostream>
#include <vector>

class Solution {
public:
    bool canReach(std::vector<int>& start, std::vector<int>& target) {
        int startParity = (start[0] + start[1]) % 2;
        int targetPrity = (target[0] + target[1]) % 2;

        return ((startParity == targetPrity) ? true : false);
    }
};

int main() {
    Solution sol;

    std::vector<int> start = {1, 1};
    std::vector<int> target = {2, 2};

    bool result = sol.canReach(start, target);
    std::cout << std::boolalpha << result << "\n";

    return 0;
}