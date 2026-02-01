def numOfWays(n : int) -> int:
    MOD = 10 ** 9 + 7

    waysSame = 6
    waysDiff = 6

    for _ in range(n - 1):
        nextWaysSame = (3 * waysSame + 2 * waysDiff) % MOD
        nextWaysDiff = (2 * waysSame + 2 * waysDiff) % MOD

        waysSame = nextWaysSame
        waysDiff = nextWaysDiff

    return (waysSame + waysDiff) % MOD

n = 5000
print(numOfWays(n))