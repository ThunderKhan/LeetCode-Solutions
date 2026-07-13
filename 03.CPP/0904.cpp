#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        int n = fruits.size();

        int left = 0;
        int maxLen = 0;
        std::unordered_map<int, int>  fruitMap;

        for (int right = 0; right < n; right++) {
            int current = fruits[right];

            fruitMap[current]++;

            while (fruitMap.size() > 2) {
                fruitMap[fruits[left]]--;

                if (fruitMap[fruits[left]] == 0) {
                    fruitMap.erase(fruits[left]);
                }

                left++;
            }

            int currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    
    std::vector<int> fruits = {1, 2, 3, 2, 2};
    int result = sol.totalFruit(fruits);

    std::cout << result << "\n";
    return 0;
}