from typing import List

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)

        if k > n:
            return -1.0

        windowSum = 0
        for i in range(k):
            windowSum += nums[i]
        
        maxSum = windowSum
        for i in range(k, n):
            windowSum += nums[i] - nums[i - k]

            if windowSum > maxSum:
                maxSum = windowSum

        return maxSum / k
    
sol = Solution()

nums = [1, 12, -5, -6, 50, 3]
k = 4

result = sol.findMaxAverage(nums, k)
print(f"The maximum average of {k}-length subarray in {nums} is {result}")