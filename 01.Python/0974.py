from typing import List

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        map = {0 : 1}

        runningSum = 0
        count = 0

        for i in range(len(nums)):
            runningSum += nums[i]
            rem = runningSum % k

            count += map.get(rem, 0)
            map[rem] = map.get(rem, 0) + 1

        return count

sol = Solution()

nums = [4, 5, 0, -2, -3, 1]
k = 5

result = sol.subarraysDivByK(nums, k)
print(result)