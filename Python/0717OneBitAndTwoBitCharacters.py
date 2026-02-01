def isOneBitCharacter(bits : list[int]) -> bool:
    i = len(bits) - 2
    count = 0

    while i >= 0 and bits[i] == 1:
        count += 1
        i -= 1
    
    return count % 2 == 0

arr1 = [1, 1, 0]
arr2 = [1, 1, 1, 0]

print(isOneBitCharacter(arr1))
print(isOneBitCharacter(arr2))