def shuffle(nums : list[int], n : int) -> list[int]:
    res = []
    for i in range(n):
        res.append(nums[i])
        res.append(nums[i + n])
    return res

nums = [1, 2, 3, 4, 5, 6, 7, 8]
n = 4
print(shuffle(nums, n))