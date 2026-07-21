from typing import List

class Solution:
    def canReach(self, start: List[int], target: List[int]) -> bool:
        startParity = (start[0] + start[1]) % 2
        targetParity = (target[0] + target[1]) % 2

        return (startParity == targetParity)
    
sol = Solution()

start = [1, 1]
target = [2, 2]

print(sol.canReach(start, target))