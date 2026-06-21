from typing import List

class Solution:
    def closestPairToTarget(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        min_diff = float('inf')

        while left < right:
            current_sum = nums[left] + nums[right]
            abs_diff = abs(current_sum - target)

            if abs_diff < min_diff:
                min_diff = abs_diff
            
            if current_sum < target:
                left += 1
            elif current_sum > target:
                right -=1
            else:
                break
        
        return min_diff

sol = Solution()

nums = [1, 3, 5, 8, 12]
target = 10
result = sol.closestPairToTarget(nums, target)
print(result)