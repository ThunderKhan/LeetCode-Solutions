#include <stdio.h>

int sum(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int num1 = 5;
    int num2 = 3;

    printf("%d", sum(num1, num2));
    return 0;
}