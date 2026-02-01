def threeSumClosest(nums : list[int], target : int) -> int:
    n = len(nums)
    nums.sort()

    bestDiff = float('inf')
    bestSum = 0

    for i in range(n - 2):
        left = i + 1
        right = n - 1

        while left < right:
            currSum = nums[i] + nums[left] + nums[right]
            diff = abs(currSum - target)
            
            if diff < bestDiff:
                bestDiff = diff
                bestSum = currSum
            
            if currSum < target:
                left += 1
            elif currSum > target:
                right -= 1
            else:
                return currSum
        
    return bestSum

nums = [0, 0, 0]
target = 1
print(threeSumClosest(nums, target))