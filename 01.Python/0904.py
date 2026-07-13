from typing import List

class Solution:
    def totalFruits(self, fruits: List[int]) -> int:
        n = len(fruits)

        fruitMap = {}
        left = 0
        maxLen = 0

        for right in range(n):
            current = fruits[right]

            if current in fruitMap:
                fruitMap[current] += 1
            else:
                fruitMap[current] = 1

            while len(fruitMap) >  2:
                fruitMap[fruits[left]] -= 1

                if fruitMap[fruits[left]] == 0:
                    del fruitMap[fruits[left]]
                left += 1

            currLen = right - left + 1
            if currLen > maxLen:
                maxLen = currLen
        
        return maxLen

sol = Solution()

fruits = [1, 2, 3, 2, 2]
print(sol.totalFruits(fruits))