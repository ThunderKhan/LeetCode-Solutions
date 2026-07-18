from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        localSum = nums[0]
        globalBestSum = nums[0]

        for num in nums[1:]:
            localSum = max(num, num + localSum)
            globalBestSum = max(globalBestSum, localSum)
        
        return globalBestSum

sol = Solution()

nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print(sol.maxSubArray(nums))