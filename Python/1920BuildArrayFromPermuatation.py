def buildArray(nums: list[int]) -> list[int]:

    n = len(nums)

    for i in range(n):
        nums[i] += (nums[nums[i]] % n) * n
    
    for i in range(n):
        nums[i] //= n
    
    return nums

nums = [0,2,1,5,3,4]
print(buildArray(nums))