def runningSum(nums : list[int]) -> int:
    n = len(nums)
    prefixSum = [0] * n

    prefixSum[0] = nums[0]

    for i in range(1, n):
        prefixSum[i] = prefixSum[i - 1] + nums[i]
    
    return prefixSum

nums = [1, 2, 3]
print(runningSum(nums))