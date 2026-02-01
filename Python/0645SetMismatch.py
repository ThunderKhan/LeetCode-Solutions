def findErrorNums(nums : list[int]) -> list[int]:
    seen = set()
    duplicate = 0
    current_sum = 0

    for num in nums:
        if num in seen:
            duplicate = num
        else:
            seen.add(num)
        
        current_sum += num
    
    n = len(nums)
    expected_sum = (n * (n + 1)) // 2

    missing = expected_sum - (current_sum - duplicate)

    return [duplicate, missing]

arr1 = [1, 2, 2, 4]
print(findErrorNums(arr1))