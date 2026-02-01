def productExceptSelf(nums : list[int]) -> list[int]:
    n = len(nums)
    prefix =  [1] * n

    prefix[0] = 1
    for i in range(1, n):
        prefix[i] = prefix[i - 1] * nums[i - 1]