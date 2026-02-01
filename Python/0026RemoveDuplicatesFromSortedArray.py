def removeDuplicates(nums : list[int]) -> int:
    low = 0
    high = 1
    uniqueCount = 1

    while(high < len(nums)):
        if nums[high] == nums[high - 1]:
            high += 1
            continue

        nums[low + 1] = nums[high]

        low += 1
        high += 1
        uniqueCount += 1
    
    return uniqueCount

nums = [1, 1, 1, 2, 2, 3]
print(removeDuplicates(nums))
print(nums)