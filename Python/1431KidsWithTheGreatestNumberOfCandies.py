def kidsWithCandies(candies : list[int], extraCandies : int) -> list[bool]:
    n = len(candies)
    candyArray = [False] * n
    maxCandy = float('-inf')

    for candy in candies:
        if candy > maxCandy:
            maxCandy = candy

    for i in range(n):
        increasedCandies = candies[i] + extraCandies
        
        if increasedCandies >= maxCandy:
            candyArray[i] = True
        
    return candyArray

candies = [2,3,5,1,3]
extraCandies = 3

print(kidsWithCandies(candies, extraCandies))