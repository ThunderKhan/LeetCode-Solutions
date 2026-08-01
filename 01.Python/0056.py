from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        result = []
        intervals.sort()

        prevStart = intervals[0][0]
        prevEnd = intervals[0][1]

        for i in range(1, len(intervals)):
            currStart = intervals[i][0]
            currEnd = intervals[i][1]

            if currStart <= prevEnd:
                prevStart = prevStart
                prevEnd = max(prevEnd, currEnd)
                continue
            else:
                result.append([prevStart, prevEnd])
                prevStart = currStart
                prevEnd = currEnd

        result.append([prevStart, prevEnd])
        return result

sol = Solution()

intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
result = sol.merge(intervals)

print(result)