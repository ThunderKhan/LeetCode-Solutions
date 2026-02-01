def totalfruits(fruits : list[int]) -> int:
    fruitMap = {}
    n = len(fruits)
    low = 0
    maxLen = 0

    for high in range(n):
        if fruits[high] in fruitMap:
            fruitMap[fruits[high]] += 1
        else:
            fruitMap[fruits[high]] = 1
        
        while len(fruitMap) > 2:
            fruitMap[fruits[low]] -= 1
            if fruitMap[fruits[low]] == 0:
                del fruitMap[fruits[low]]
            low += 1
        
        length = high - low + 1
        if length > maxLen:
            maxLen = length
    
    
    return maxLen

fruits = [1, 2, 3, 2, 2]
result = totalfruits(fruits)

print(f"\nThe maximum numeber of fruits we can pick is {result}")