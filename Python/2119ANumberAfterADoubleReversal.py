def isSameAfterReversal(num : int) -> bool:
    original = num
    
    reverse1 = 0
    while num > 0:
        reverse1 = (reverse1 * 10) + (num % 10)
        num //= 10
    
    reverse2 = 0
    while reverse1 > 0:
        reverse2 = (reverse2 * 10) + (reverse1 % 10)
        reverse1 //= 10
    
    return original == reverse2

num = 526
print(isSameAfterReversal(num))

num = 1800
print(isSameAfterReversal(num))

num = 0
print(isSameAfterReversal(num))