def findMaxAverage(nums : list[int], k : int) -> float:
    n = len(nums)

    if k > n:
        return None

    windowSum = 0
    for i in range(k):
        windowSum += nums[i]
    
    maxSum = windowSum
    for i in range(k, n):
        windowSum += nums[i] - nums[i - k]

        if windowSum > maxSum:
            maxSum = windowSum
        
    maxAvg = maxSum / k
    return maxAvg

nums = [1,12,-5,-6,50,3]
k = 4

print(findMaxAverage(nums, k))