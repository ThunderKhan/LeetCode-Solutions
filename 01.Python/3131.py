from typing import List

class Solution:
    def addedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        x1 = min(nums1)
        x2 = min(nums2)

        return x2 - x1

sol = Solution()

nums1 = [2, 6, 4]
nums2 = [9, 7, 5]

print(sol.addedInteger(nums1, nums2))