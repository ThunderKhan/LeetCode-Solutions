def getSneakyNumbers(nums : list[int]) -> list[int]:
    seen = set()

    ans = []
    for num in nums:
        if num in seen:
            ans.append(num)
        else:
            seen.add(num)
    
    return ans

nums = [7,1,5,4,3,4,6,0,9,5,8,2]
print(getSneakyNumbers(nums))