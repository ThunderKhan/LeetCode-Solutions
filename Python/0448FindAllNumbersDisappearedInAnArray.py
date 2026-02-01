def findDisappearedNumbers(nums : list[int]) -> list[int]:
    n = len(nums)

    for i in range(n):
        val = abs(nums[i])
        idx = val - 1

        if nums[idx] > 0:
            nums[idx] = -nums[idx]
    
    missing = []
    for i in range(n):
        if nums[i] > 0:
            missing.append(i + 1)
    
    return missing