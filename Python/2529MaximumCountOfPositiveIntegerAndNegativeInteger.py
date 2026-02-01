def maximumCount(nums : list[int]) -> int:

    pos = 0
    neg = 0
    n = 0

    for num in nums:
        if num > 0:
            pos += 1
        
        if num < 0:
            neg += 1
    
    if pos > neg:
        n = pos
    else:
        n = neg
    
    return n

nums = [-3,-2,-1,0,0,1,2]
print(maximumCount(nums))