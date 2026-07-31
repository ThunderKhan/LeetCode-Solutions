from typing import List

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        map = {0 : -1}

        runningSum = 0
        maxLen = 0

        for i in range(len(nums)):
            if nums[i] == 0:
                runningSum -= 1
            else:
                runningSum += 1

            if runningSum in map:
                currLen = i - map[runningSum]
                maxLen = max(maxLen, currLen)
            else:
                map[runningSum] = i
        
        return maxLen


sol = Solution()

nums = [0, 1, 1, 1, 1, 1, 0, 0, 0]
result = sol.findMaxLength(nums)

print(result)