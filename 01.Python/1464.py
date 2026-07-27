from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max1 = max2 = 0

        for num in nums:
            if num > max1:
                max2 = max1
                max1 = num
            elif num > max2:
                max2 = num
        

        return ((max1 - 1) * (max2 - 1))

sol = Solution()

nums = [3, 4, 5, 2]
resul = sol.maxProduct(nums)

print(nums)