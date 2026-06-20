from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1

        while left < right:
            result_sum = numbers[left] + numbers[right]

            if result_sum < target:
                left += 1
            elif result_sum > target:
                right -= 1
            else:
                return [left + 1, right + 1]
        
        return [-1, -1]

if __name__ == "__main__":
    sol = Solution()

    numbers = [2,7,11,15]
    target = 9
    print(f"Test 1: {sol.twoSum(numbers, target)}") # Expected: [1, 2]