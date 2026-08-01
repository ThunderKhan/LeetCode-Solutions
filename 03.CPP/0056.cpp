#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> result;

        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currStart <= prevEnd) {
                prevStart = prevStart;
                prevEnd = std::max(prevEnd, currEnd);
                continue;
            } else {
                result.push_back({prevStart, prevEnd});
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }

        result.push_back({prevStart, prevEnd});
        return result;
    }
};

void printVector(std::vector<std::vector<int>>& vec) {
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << "[";
        std::cout << vec[i][0] << ", " << vec[i][1];
        std::cout << "]";

        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << "\n";
}

int main() {
    Solution sol;

    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<std::vector<int>> result = sol.merge(intervals);

    printVector(result);
    return 0;
}