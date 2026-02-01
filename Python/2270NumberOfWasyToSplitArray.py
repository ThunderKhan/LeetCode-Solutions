def waysToSplitArray(nums : list[int]) -> int:
    totalSum = 0
    for num in nums:
        totalSum += num

    countSplit = 0
    leftSum = 0

    for i in range(len(nums) - 1):
        leftSum += nums[i]

        rightSum = totalSum - leftSum

        if leftSum >= rightSum:
            countSplit += 1
        
    return countSplit

nums = [2, 3, 1, 0]
print(waysToSplitArray((nums)))