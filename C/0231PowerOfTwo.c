#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n){
    if (n > 0 && (n & (n - 1)) == 0){
        return true;
    } else{
        return false;
    }
}

int main() {

    int n = 5;
    printf("%d\n", isPowerOfTwo(n));

    return 0;
}