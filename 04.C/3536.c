#include <stdio.h>
#include <limits.h>

int maxProduct(int n) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;

    while (n > 0) {
        int digit = n % 10;

        if (digit > max1) {
            max2 = max1;
            max1 = digit;
        } else if (digit > max2) {
            max2 = digit;
        }

        n /= 10;
    }

    return max1 * max2;
}

int main() {
    int n = 1234;
    int result = maxProduct(n);

    printf("%d", result);
    return 0;
}