def findFinalValue(nums : list[int], original : int) -> int:
    seen = set(nums)

    while True:
        if original not in seen:
            break
        else:
            if original == 0:
                return 0
            original *= 2
    

    return original

nums = [5, 3, 6, 1, 12]
original = 3
print(findFinalValue(nums, original))