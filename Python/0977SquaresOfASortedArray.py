def sortedSquares(nums : list[int]) -> list[int]:
    result = [0] * len(nums)

    left = 0 
    right = len(nums) - 1
    write = len(nums) - 1

    while left <= right:
        if abs(nums[left]) > abs(nums[right]):
            result[write] = nums[left] * nums[left]
            left += 1
        else:
            result[write] = nums[right] * nums[right]
            right -= 1
        write -= 1
    
    return result

nums = [-4, -1, 0, 3, 4, 10]
print(sortedSquares(nums))