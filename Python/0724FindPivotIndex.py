def pivotIndex(nums : list[int]) -> int:
    totalSum = 0
    for num in nums:
        totalSum += num
    
    leftSum = 0
    for i in range(len(nums)):
        rightSum = totalSum - leftSum - nums[i]

        if rightSum == leftSum:
            return i
        
        leftSum += nums[i]
    
    return -1

nums = [2, 3, -1, 8, 4]
print(pivotIndex(nums))