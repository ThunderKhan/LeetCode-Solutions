from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        hashMap = {0 : 1}

        count = 0
        runningSum = 0

        for num in nums:
            runningSum += num
            diff = runningSum - k

            if diff in hashMap:
                count += hashMap[diff]

            hashMap[runningSum] = hashMap.get(runningSum, 0) + 1

        return count

sol = Solution()

nums = [1, 1, 1]
k = 2

result = sol.subarraySum(nums, k)
print(result)