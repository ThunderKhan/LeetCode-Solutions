#include <ios>
#include <iostream>

int squaresOfDigit(int n) {
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
    slow = squaresOfDigit(slow);
    fast = squaresOfDigit(squaresOfDigit(fast));

    if ((slow == fast) && (slow != 1)) {
      return false;
    }
  }
  return true;
}

int main() {
  int n = 19;
  
  bool result = isHappy(n);
  std::cout << std::boolalpha();
  std::cout << result << std::endl;

  return 0;
}
