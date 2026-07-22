from typing import List

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        localMax = nums[0]
        globalMax = nums[0]

        localMin = nums[0]
        globalMin = nums[0]

        totalSum = nums[0]

        for i in range(1, len(nums)):
            localMax = max(nums[i], localMax + nums[i])
            globalMax = max(globalMax, localMax)

            localMin = min(nums[i], nums[i] + localMin)
            globalMin = min(globalMin, localMin)

            totalSum += nums[i]

        if globalMin == totalSum:
            return globalMax

        wrappingSum = totalSum - globalMin
        result = max(globalMax, wrappingSum)

        return result

sol = Solution()

nums1 = [1, -2, 3, -2]
resutlt1 = sol.maxSubarraySumCircular(nums1)
print(resutlt1)

nums2 = [5, -3, 5]
result2 = sol.maxSubarraySumCircular(nums2)
print(result2)

nums3 = [-3, -2, -3]
result3 = sol.maxSubarraySumCircular(nums3)
print(result3)