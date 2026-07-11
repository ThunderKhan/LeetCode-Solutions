#include <iostream>

class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};

int main() {
    Solution sol;
    
    int num1 = 5;
    int num2 = 3;

    std::cout << sol.sum(num1, num2) << "\n";
    return 0;
}