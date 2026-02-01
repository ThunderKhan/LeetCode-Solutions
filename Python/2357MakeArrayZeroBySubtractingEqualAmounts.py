def minimumOperations(nums : list[int]) -> int:
    seen = set()
    nonZeroCount = 0

    for i in range(len(nums)):
        if (nums[i] != 0) and (nums[i] not in seen):
            nonZeroCount += 1
            seen.add(nums[i])

    return nonZeroCount

nums = [1, 5, 0, 3, 5]
result = minimumOperations(nums)

print(f"The minimum number of operations required to make the array zero is: {result}")
