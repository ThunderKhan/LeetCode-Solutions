#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& firstList, std::vector<std::vector<int>>& secondList) {
        std::vector<std::vector<int>> result;

        int i = 0;
        int j = 0;

        while ((i < firstList.size()) && (j < secondList.size())) {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            if ((std::max(start1, start2)) <= (std::min(end1, end2))) {
                result.push_back({std::max(start1, start2), std::min(end1, end2)});
            }

            if (end1 <= end2) {
                i++;
            } else {
                j++;
            }
        }

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

    std::vector<std::vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    std::vector<std::vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

    std::vector<std::vector<int>> result = sol.intervalIntersection(firstList, secondList);

    printVector(result);
    return 0;
}