def maxProfit(prices : list[int]) -> int:

    minPrice = prices[0]
    maximumProfit = 0

    for i in range(1, len(prices)):
        profit = prices[i] - minPrice

        if profit > maximumProfit:
            maximumProfit = profit
        
        if prices[i] < minPrice:
            minPrice = prices[i]
    
    return maximumProfit

prices = [7]
print(maxProfit(prices))