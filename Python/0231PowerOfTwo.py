def isPowerTwo(n : int) -> bool:
    return n > 0 and (n & (n - 1)) == 0
    
n = 3
print(isPowerTwo(n))