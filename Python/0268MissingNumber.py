def missingNumber(nums : list[int]) -> int:
    n = len(nums)
    expected_sum = (n * (n + 1)) // 2
    current_sum = 0
    
    for num in nums:
        current_sum += num
    
    return abs(expected_sum - current_sum)

arr = [0, 1, 3]
print(missingNumber(arr))