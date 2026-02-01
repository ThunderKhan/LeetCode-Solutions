def maximumScore(nums : list[int]) -> int:
    n = len(nums)

    prefixSum = [0] * n
    prefixSum[0] = nums[0]

    for i in range(1, n):
        prefixSum[i] = prefixSum[i - 1] + nums[i]

    suffixMin = [float('inf')] * n

    for i in range(n - 2, -1, -1):
        if nums[i + 1] < suffixMin[i + 1]:
            suffixMin[i] = nums[i + 1]
        else:
            suffixMin[i] = suffixMin[i + 1]

    maxScore = 0
    for i in range(n):
        score = prefixSum[i] - suffixMin[i]

        if score > maxScore:
            maxScore = score
    
    return maxScore

nums = [10,-1,3,-4,-5]
print(maximumScore(nums))