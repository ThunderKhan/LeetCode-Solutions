from typing import List

class Solution:
    def numberOfSmallerPairs(self, nums: List[int], target: int) -> int:
        count = 0
        left = 0
        right = len(nums) - 1

        while left < right:
            currentSum = nums[left] + nums[right]
            
            if currentSum < target:
                count += right - left
                left += 1
            else:
                right -= 1
        
        return count
    
sol = Solution()
nums = [1, 2, 3, 4]
target = 6
result = sol.numberOfSmallerPairs(nums, target)
print(result)