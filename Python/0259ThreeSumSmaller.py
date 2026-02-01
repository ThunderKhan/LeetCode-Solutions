def threeSumSamller(nums : list[int], target : int) -> int:
    tripletCount = 0
    n = len(nums)
    nums.sort()

    for i in range(n - 2):
        left = i + 1
        right = n - 1
        
        while left < right:
            sum = nums[i] + nums[left] + nums[right]

            if sum < target:
                tripletCount += (right - left)
                left += 1            
            else:
                right -= 1
    
    return tripletCount

nums = [-2, 0, 1, 3]
target = 2
print(threeSumSamller(nums, target))

nums = [-5, -4, -3, -2]
target = -3
print(threeSumSamller(nums, target))