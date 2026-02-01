#include <stdio.h>

int numOfWays(int n) {
    const int MOD = 1000000007;

    long long waysSame = 6;
    long long waysDiff = 6;

    for(int i = 1; i < n; i++){
        long long nextWaysSame = (3 * waysSame + 2 * waysDiff) % MOD;
        long long nextWaysDiff = (2 * waysSame + 2 * waysDiff) % MOD;

        waysSame = nextWaysSame;
        waysDiff = nextWaysDiff;
    }

    return (int)((waysSame + waysDiff) % MOD);
}

int main(){

    int n = 5000;
    printf("%d", numOfWays(n));

    return 0;
}