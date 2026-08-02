from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        result = []

        prevStart = intervals[0][0]
        prevEnd = intervals[0][1]

        for i in range(1, len(intervals)):
            currStart = intervals[i][0]
            currEnd = intervals[i][1]

            if currStart <= prevEnd:
                prevStart = prevStart
                prevEnd = max(prevEnd, currEnd)
            else:
                result.append([prevStart, prevEnd])
                prevStart = currStart
                prevEnd = currEnd


        result.append([prevStart, prevEnd])
        return result


    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        result = []

        inserted = False
        for i in range(len(intervals)):
            currStart = intervals[i][0]

            if not inserted and currStart >= newInterval[0]:
                result.append(newInterval)
                inserted = True

            result.append(intervals[i])

        if not inserted:
            result.append(newInterval)

        return self.merge(result)

sol = Solution()

intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]] 
newInterval = [4, 8]

result = sol.insert(intervals, newInterval)
print(result)