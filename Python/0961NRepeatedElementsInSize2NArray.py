def repeatedNTimes(nums : int) -> int:
    seen = set()

    for num in nums:
        if num in seen:
            return num
        seen.add(num)
    
    return -1

nums = [1,2,3,3]
print(repeatedNTimes(nums))