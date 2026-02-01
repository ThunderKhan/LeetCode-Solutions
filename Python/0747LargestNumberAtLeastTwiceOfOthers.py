def dominantIndex(nums : list[int]) -> int:
    largest = nums[0]
    largestIdx = 0
    for i in range(len(nums)):
        if nums[i] > largest:
            largest = nums[i]
            largestIdx = i
    
    for i in range(len(nums)):
        if nums[i] == largest:
            continue
        
        if (2 * nums[i]) > largest:
            return -1
    
    return largestIdx
        
nums = [1, 2, 3, 4]
print(dominantIndex(nums))