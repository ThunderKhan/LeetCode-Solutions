#include <iostream>

using namespace std;

int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    int prev = 1;
    int curr = 1;

    for (int i = 2; i < (n + 1); ++i) {
        curr = curr - prev;
        prev = curr + prev;
    }

    return curr;
}

int main() {

    int n = 5;
    cout << climbStairs(n) << endl;

    return 0;
}