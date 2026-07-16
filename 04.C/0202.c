#include <stdio.h>
#include <stdbool.h>

int squareSum(int n ) {
    int sumOfSquares = 0;

    while (n) {
        int digit = n % 10;
        sumOfSquares += digit * digit;
        n /= 10;
    }

    return sumOfSquares;
}

bool isHappy(int n){
    if (n == 1) {
        return true;
    }

    int slow = n;
    int fast = n;

    while (fast != 1) {
        slow = squareSum(slow);
        fast = squareSum(squareSum(fast));

        if ((slow == fast) && (slow != 1)) {
            return false;
        }
    }

    return true;
}

int main() {
    int n1 = 19;
    printf("%d\n", isHappy(n1));
    
    int n2 = 2;
    printf("%d\n", isHappy(n2));

    return 0;
}