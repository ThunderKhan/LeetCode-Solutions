def two_sum(nums : list[int], target : int) -> list[int]:
    hash_map = {}

    for i, x in enumerate(nums):
        complement = target - x

        if complement in hash_map:
            return [i, hash_map[complement]]
        hash_map[x] = i

arr1 = [1, 2]
target1 = 3
print(two_sum(arr1, target1))

arr2 = [3, 3]
target2 = 6
print(two_sum(arr2, target2))

arr3 = [-1, 4, 2]
target3 = 1
print(two_sum(arr3, target3))