from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        low = 0
        high = 1
        uniqueCount = 1
        n = len(nums)

        while high < n:
            if nums[high] == nums[high - 1]:
                high += 1
                continue
            
            nums[low + 1] = nums[high]
            low += 1
            high += 1
            uniqueCount += 1
        
        return uniqueCount

sol = Solution()

nums = [1, 1, 1, 2, 2, 3]
result = sol.removeDuplicates(nums)

print(nums)
print(result)