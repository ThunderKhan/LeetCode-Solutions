from typing import List

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)

        left = 0
        maxLen = 0
        zeroCount = 0

        for right in range(n):
            if nums[right] == 0:
                zeroCount += 1
            
            while zeroCount > k:
                if nums[left] == 0:
                    zeroCount -= 1
                
                left += 1

            currLen = right - left + 1
            maxLen = max(maxLen, currLen)
        
        return maxLen

sol = Solution()

nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0]
k = 2

result = sol.longestOnes(nums, k)
print(result)