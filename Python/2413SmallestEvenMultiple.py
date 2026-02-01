def smallestEvenMultiple(n : int ) -> int:
    return n if (n % 2 == 0) else (2 * n)

n = 5
print(smallestEvenMultiple(n))

n = 6
print(smallestEvenMultiple(n))