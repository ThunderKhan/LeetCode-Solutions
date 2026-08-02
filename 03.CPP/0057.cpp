#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> intervals) {
        std::vector<std::vector<int>> result;

        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currStart <= prevEnd) {
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

    std::vector<std::vector<int>> insert(std::vector<std::vector<int>> intervals, std::vector<int> newInterval) {
        std::vector<std::vector<int>> result;
        bool inserted = false;

        for (int i = 0; i < intervals.size(); i++) {
            int currStart = intervals[i][0];

            if (!inserted && (currStart >= newInterval[0])) {
                result.push_back(newInterval);
                inserted = true;
            }

            result.push_back(intervals[i]);
        }

        if (!inserted) {
            result.push_back(newInterval);
        }

        return merge(result);
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

    std::vector<std::vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    std::vector<int> newInterval = {4, 8};

    std::vector<std::vector<int>> result = sol.insert(intervals, newInterval);

    printVector(result);
    return 0;
}