def isPowerOfFour(n : int) -> bool:
    return n > 0 and (n & (n - 1)) == 0 and (n & 0x55555555) != 0

n = 5
print(isPowerOfFour(n))

n = 16
print(isPowerOfFour(n))