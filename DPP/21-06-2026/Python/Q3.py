from typing import List

class Solution:
    def numberOfPairs(self, weights: List[int], target: int) -> int:
        left = 0
        right = len(weights) - 1

        count = 0

        while left < right:
            currentSum = weights[left] + weights[right]

            if currentSum < target:
                left += 1
            elif currentSum > target:
                right -= 1
            else:
                count += 1
        
        return count

sol = Solution()
weights = [1, 1, 2, 2, 3, 3]
target = 4
result = sol.numberOfPairs(weights, target)
print(result)