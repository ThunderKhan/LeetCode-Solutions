def twoSumLessThanK(nums : list[int], k : int) -> int:
    maxSum = float('-inf')
    nums.sort()

    left = 0
    right = len(nums) - 1

    while left < right:
        currSum = nums[left] + nums[right]

        if currSum < k:
            if currSum > maxSum:
                maxSum = currSum
            left += 1
        else:
            right -= 1
    

    return maxSum


nums = [34, 23, 1, 24, 75, 33, 54, 8]
k = 60

result = twoSumLessThanK(nums, k)
print(f"The maximum sum less than k in the array is: {result}.")