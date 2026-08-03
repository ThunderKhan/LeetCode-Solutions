from typing import List

class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        result = []

        i = 0
        j = 0

        while i < len(firstList) and j < len(secondList):
            start1 = firstList[i][0]
            end1 = firstList[i][1]
            
            start2 = secondList[j][0]
            end2 = secondList[j][1]

            if max(start1, start2) <= min(end1, end2):
                result.append([max(start1, start2), min(end1, end2)])

            if end1 <= end2:
                i += 1
            else:
                j += 1

        return result

sol = Solution()

firstList = [[0, 2], [5, 10], [13, 23], [24, 25]]
secondList = [[1, 5], [8, 12], [15, 24], [25, 26]]

result = sol.intervalIntersection(firstList, secondList)
print(result)