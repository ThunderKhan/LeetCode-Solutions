def minimumOperations(nums : list[int]) -> int:
    counter = 0

    for num in nums:
        if num % 3 != 0:
            k = num % 3
            if 3 - k > k:
                counter += k
            else:
                counter += (3 - k)
    
    return counter

nums = [1, 2, 3, 4]
print(minimumOperations(nums))