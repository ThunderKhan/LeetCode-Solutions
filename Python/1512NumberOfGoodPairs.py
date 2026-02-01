def numIdenticalPairs(nums : list[int]) -> int:
    goodPairs =  0
    freqMap = {}

    for num in nums:
        goodPairs += freqMap.get(num, 0)
        freqMap[num] = freqMap.get(num, 0) + 1
    
    return goodPairs

nums = [1, 2, 3, 1, 1, 3]
print(numIdenticalPairs(nums))