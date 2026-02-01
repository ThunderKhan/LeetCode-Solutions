def maxSubarray(nums : list[int]) -> int:

    currSum = 0
    maxSum = float('-inf')
    
    for num in nums:
        currSum += num

        if currSum > maxSum:
            maxSum = currSum

        if currSum < 0:
            currSum = 0
    
    return maxSum

nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print(maxSubarray(nums))