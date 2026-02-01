def climbStairs(n : int) -> int:
    if n == 1 or n == 0:
        return 1
    
    prev = 1
    curr = 1
    for _ in range(2, n + 1):
        curr = curr + prev
        prev = curr - prev
    
    return curr

n = 8
print(climbStairs(n))