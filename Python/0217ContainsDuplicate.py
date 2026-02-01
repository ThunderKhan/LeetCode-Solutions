def containsDuplicate(nums : list[int]) -> bool:
    seen = set()

    for x in nums:
        if x in seen:
            return True
        seen.add(x)
    return False

# def containsDuplicate(nums : list[int]) -> bool:
#     return len(set(nums)) != len(nums)

arr1 = [1, 2, 3, 1]
print(containsDuplicate(arr1))

arr2 = [1, 2, 3, 4]
print(containsDuplicate(arr2))