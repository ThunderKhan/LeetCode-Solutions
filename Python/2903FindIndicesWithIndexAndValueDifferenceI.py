def findIndices(nums : list[int], indexDifference : int, valueDifference : int) -> list[int]:
    n = len(nums)

    for i in range(n):
        for j in range(i + 1, n):
            if ((abs(i - j)) >= indexDifference):
                if ((abs(nums[i] - nums[j]) >= valueDifference)):
                    return [i, j]
    
    return [-1, -1]


nums = [5, 1, 4, 1] 
indexDifference = 2 
valueDifference = 4

print(findIndices(nums, indexDifference, valueDifference))