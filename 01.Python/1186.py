from typing import List

class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        noDelSum = arr[0]
        oneDelSum = -10_000
        result = arr[0]

        for i in range(1, len(arr)):
            prevNoDel = noDelSum

            noDelSum = max(arr[i], arr[i] + noDelSum)
            oneDelSum = max(prevNoDel, arr[i] + oneDelSum)

            result = max(result, noDelSum, oneDelSum)
        
        return result

sol = Solution()

arr1 = [1, -2, 0, 3]
result1 = sol.maximumSum(arr1)

arr2 = [1, -2, -2, 3]
result2 = sol.maximumSum(arr2)

arr3 = [-1, -1, -1, -1]
result3 = sol.maximumSum(arr3)

print(result1)
print(result2)
print(result3)