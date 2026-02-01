def checkIfExist(arr : list[int]) -> bool:
    seen = set(arr)

    zeroCount = 0
    for num in arr:
        if num == 0:
            zeroCount += 1
    
    for num in arr:
        if num == 0:
            if zeroCount > 1:
                return True
        else:
            if (2 * num) in seen:
                return True
    
    return False

arr = [10, 2, 5, 3]
print(checkIfExist(arr))