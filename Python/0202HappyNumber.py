def squareOfDigits(n : int) -> int:
    sumOfSquare = 0
    while n:
        digit = n % 10
        n //= 10
        sumOfSquare += digit * digit

    return sumOfSquare

def isHappy(n : int) -> bool:
    slow = n
    fast = n

    while fast != 1:
        slow = squareOfDigits(slow)
        fast = squareOfDigits(squareOfDigits(fast))

        if (slow == fast) and (slow != 1):
            return False

    return True

n = 19
print(isHappy(n))
