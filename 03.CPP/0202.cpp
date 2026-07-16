#include <iostream>

class Solution {
public:
    int squareSum(int n) {
        int sumOfSquares = 0;

        while (n > 0) {
            int digit = n % 10;
            sumOfSquares += digit * digit;
            n /= 10;
        }

        return sumOfSquares;
    }

    bool isHappy(int n) {
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
};

int main() {
    Solution sol;

    int n1 = 19;
    bool result1 = sol.isHappy(n1);
    
    int n2 = 2;
    bool result2 = sol.isHappy(n2);

    std::cout << std::boolalpha << result1 << "\n" << result2 << "\n";
    return 0;
}