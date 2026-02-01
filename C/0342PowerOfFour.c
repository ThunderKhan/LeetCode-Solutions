#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int n){
    return (n > 0) && ((n & (n - 1)) == 0) && ((n & 0x55555555) != 0);
}

int main(){

    int n = 16;
    printf("%d", isPowerOfFour(n));

    return 0;
}