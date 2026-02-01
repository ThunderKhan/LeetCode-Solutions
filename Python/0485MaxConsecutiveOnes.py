def findMaxConsecutiveOnes(nums : list[int]) -> int:
    counter = 0
    max_count = 0
    for x in nums:
        if x == 1:
            counter += 1
        else:
            max_count = max(counter, max_count)
            counter = 0
    
    max_count = max(counter, max_count)
    return max_count

arr = [1, 1, 0, 1, 1, 1]
print(findMaxConsecutiveOnes(arr))

arr2 = [1, 0, 1, 1, 0, 1]
print(findMaxConsecutiveOnes(arr2))