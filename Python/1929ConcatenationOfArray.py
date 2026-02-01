def getConcatenation(nums : list[int]) -> list[int]:
    ans = [0] * (2 * len(nums))

    for i, x in enumerate(nums):
        ans[i] = nums[i]
        ans[i + len(nums)] = nums[i]
    
    return ans


nums = [1, 2, 3]
print(getConcatenation(nums))