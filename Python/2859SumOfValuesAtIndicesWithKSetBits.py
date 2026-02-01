def sumIndicesWithKSetBits(nums : list[int], k : int) -> int:
    n = len(nums)
    setBits = [0] * n

    for i in range(1, n):
        setBits[i] = setBits[i >> 1] + (i & 1)
    
    total = 0
    for i in range(n):
        if setBits[i] == k:
            total += nums[i]
    
    return total

nums = [5,10,1,5,2]
k = 1
print(sumIndicesWithKSetBits(nums, k))