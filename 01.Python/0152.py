from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxProductEndingHere = nums[0]
        minProductEndingHere = nums[0]
        maximumProduct = nums[0]

        for i in range(1, len(nums)):
            current = nums[i]

            previousMax = maxProductEndingHere
            previousMin = minProductEndingHere

            maxProductEndingHere = max(
                current,
                current * previousMax,
                current * previousMin
            )

            minProductEndingHere = min(
                current,
                current * previousMax,
                current * previousMin
            )

            maximumProduct = max(
                maximumProduct,
                maxProductEndingHere
            )

        return maximumProduct
    
sol = Solution()

nums = [2, 3, -2, 4]
result = sol.maxProduct(nums)

print(result)