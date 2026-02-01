def subarrySum(nums : list[int], k : int) -> int:
    prefixMap = {0 : 1}
    
    count =  0
    currSum = 0

    for num in nums:
        currSum += num

        if currSum - k in prefixMap:
            count += prefixMap[currSum - k]
        
        prefixMap[currSum] = prefixMap.get(currSum, 0) + 1
    
    return count