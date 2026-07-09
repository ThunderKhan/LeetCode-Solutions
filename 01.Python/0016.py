from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)

        closestSum = 0
        closestDiff = float('inf')

        for i in range(n - 2):
            left = i + 1
            right = n - 1

            while left < right:
                currSum = nums[i] + nums[left] + nums[right]
                currDiff = abs(currSum - target)

                if currDiff < closestDiff:
                    closestDiff = currDiff
                    closestSum = currSum

                if currSum < target:
                    left += 1
                elif currSum > target:
                    right -= 1
                else:
                    return currSum

        return closestSum
    
sol = Solution()

nums = [-1,2,1,-4]
target = 1

result = sol.threeSumClosest(nums, target)
print(result)