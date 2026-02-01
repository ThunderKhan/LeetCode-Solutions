#include <stdio.h>

int smallestEvenMultiple(int n){
    return (n % 2 == 0) ? n : 2 * n;
}

int main(){

    int n = 5;
    printf("%d\n", smallestEvenMultiple(n));
    
    int k = 6;
    printf("%d", smallestEvenMultiple(k));

    return 0;
}