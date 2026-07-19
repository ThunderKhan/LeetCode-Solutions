#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            minPrice = std::min(minPrice, prices[i]);
            int profitIfSoldToday = prices[i] - minPrice;

            maxProfit = std::max(profitIfSoldToday, maxProfit);
        }

        return maxProfit;
    }
};

int main() {
    Solution sol;

    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = sol.maxProfit(prices);

    std::cout << result << "\n";
    return 0;
}