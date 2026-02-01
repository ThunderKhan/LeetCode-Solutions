def minSubArrayLen(nums : list[int], target : int) -> int:
    n = len(nums)
    low = 0
    windowSum = 0
    minLen = float('inf')

    for high in range(n):
        windowSum += nums[high]

        while windowSum >= target:
            length = high - low + 1
            if length < minLen:
                minLen = length
            windowSum -= nums[low]
            low += 1

    return 0 if (minLen == float('inf')) else minLen

target = 7 
nums = [2, 3, 1, 2, 4, 3]

result = minSubArrayLen(nums, target)

print(result)