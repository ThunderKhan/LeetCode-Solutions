def isPalindrome(x : int) -> bool:
    if x < 0:
        return False
    
    if x % 10 == 0 and x != 0:
        return False
    
    reverseHalf = 0

    while x > reverseHalf:
        digit = x % 10
        reverseHalf = reverseHalf * 10 + digit
        x //= 10
    
    return x == reverseHalf or x == reverseHalf // 10