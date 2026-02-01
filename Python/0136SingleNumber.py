def singleNumber(nums : list[int]) -> int:
    unique = 0
    for num in nums:
        unique ^= num
    return unique

arr = [1, 2, 3, 2, 1]
print(singleNumber(arr))