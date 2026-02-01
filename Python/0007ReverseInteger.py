def reverse(x : int) -> int:
    
    max_int = (2 ** 31 - 1)
    
    isNegative = False
    if x < 0:
        isNegative = True
        x *= -1

    rev = 0
    while x > 0:
        digit = x % 10
        if (rev > max_int // 10) or (rev == max_int // 10 and digit > 7):
            return 0
        rev = (rev * 10) + digit
        x //= 10
    
    return -rev if isNegative else rev

x = 45
print(reverse(x))

x = -45
print(reverse(x))