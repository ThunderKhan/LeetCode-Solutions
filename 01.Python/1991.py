from typing import List

class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        totalSum = sum(nums)
        left = 0

        for i in range(len(nums)):
            right = totalSum - left - nums[i]

            if left == right:
                return i

            left += nums[i]
            
        
        return -1