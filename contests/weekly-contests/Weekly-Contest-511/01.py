from typing import List

class Solution:
    def canReach(self, start: list[int], target: list[int]) -> bool:
        start_parity = (start[0] + start[1]) % 2
        target_parity = (target[0] + target[1]) % 2

        return start_parity == target_parity