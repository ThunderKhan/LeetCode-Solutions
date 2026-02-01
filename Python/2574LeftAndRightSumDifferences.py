def leftRightDifference(nums : list[int]) -> int:
    leftSum = 0

    rightSum = 0
    for num in nums:
        rightSum += num

    answer = []

    for num in nums:
        leftSum += num
        answer.append(abs(rightSum - leftSum))
        rightSum -= num
    
    return answer

nums = [10, 4, 8, 3]
print(leftRightDifference(nums))