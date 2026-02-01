def differenceOfSum(n : int, m : int) -> int:
    total_sum = (n * (n + 1)) // 2
    k = n // m
    divisible_sum = m * (k * (k + 1)) // 2
    return total_sum - 2 * divisible_sum

n = 10
m = 3

print(differenceOfSum(n, m))