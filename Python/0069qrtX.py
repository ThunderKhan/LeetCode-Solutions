def mySqrt(x : int) -> int:
    
    if x == 0:
        return 0
    if x == 1:
        return 1
    
    left = 0
    right = x // 2
    ans = 0

    while left <= right:
        mid = left + (right - left) // 2
        square = mid * mid

        if square == x:
            return mid
        elif square < x:
            ans = mid
            left = mid + 1
        else:
            right = mid - 1
        
    return ans