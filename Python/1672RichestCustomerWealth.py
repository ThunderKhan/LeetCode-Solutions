def maximumWealth(accounts: list[list[int]]) -> int:
    maxWealth = float('-inf')

    for account in accounts:
        accountSum = 0

        for money in account:
            accountSum += money
        
        if accountSum > maxWealth:
            maxWealth = accountSum
        
    return maxWealth

accounts = [[1, 2, 3], [3, 2, 1]]
print(maximumWealth(accounts))