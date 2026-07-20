from typing import List

class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        posLocalSum = nums[0]
        negLocalSum = nums[0]
        absMaxSum = 0

        for i in range(1, len(nums)):
            posLocalSum = max(nums[i], nums[i] + posLocalSum)
            negLocalSum = min(nums[i], nums[i] + negLocalSum)

            absMaxSum = max(absMaxSum, abs(posLocalSum), abs(negLocalSum))

        return absMaxSum

sol = Solution()

nums = [1, -3, 2, 3, -4]
result = sol.maxAbsoluteSum(nums)

print(result)