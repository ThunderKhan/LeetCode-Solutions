#include <stdio.h>

int differenceOfSum(int n, int m){
    int totalSum = (n * (n + 1)) / 2;
    int k = n / m;
    int differenceSum = m * (k * (k + 1)) / 2;
    return totalSum - 2 * differenceSum;
}

int main(){
    int n = 10;
    int m = 3;

    printf("%d", differenceOfSum(n, m));

    return 0;
}