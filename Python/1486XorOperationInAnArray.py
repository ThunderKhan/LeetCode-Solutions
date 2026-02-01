def xorOperation(n : int, start : int) -> int:
    ans = 0

    for i in range(n):
        ans ^= start + 2 * i

    return ans
    
n = 5
start = 0
print(xorOperation(5, 0))