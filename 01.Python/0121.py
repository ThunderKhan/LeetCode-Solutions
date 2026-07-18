from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minimumPrice = prices[0]
        bestProfit = 0

        for price in prices:
            minimumPrice = min(minimumPrice, price)
            profitIfSoldToday = price - minimumPrice

            bestProfit = max(bestProfit, profitIfSoldToday)
        
        return bestProfit

sol = Solution()

prices = [7, 1, 5, 3, 6, 4]
result = sol.maxProfit(prices)

print(result)