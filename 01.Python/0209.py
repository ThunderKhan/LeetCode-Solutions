from typing import List

class Solution:
    def minSubarrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)

        left = 0
        windowSum = 0
        minLen = float('inf')

        for right in range(n):
            windowSum += nums[right]

            while windowSum >= target:
                currLen = right - left + 1
                if currLen < minLen:
                    minLen = currLen

                windowSum -= nums[left]
                left += 1

        if minLen == float('inf'):
            return 0
        else:
            return minLen


sol = Solution()
target = 7
nums = [2, 3, 1, 2, 4, 3]

print(sol.minSubarrayLen(target, nums))