public class LC0202HappyNumber {
  public static void main(String[] args) {
    int n = 19;
    boolean result = isHappy(n);
    System.out.println(result);
  }

  public static int sumOfSquares(int n) {
    int squaresOfDigits = 0;
    while (n > 0) {
      int digit = n % 10;
      squaresOfDigits += digit * digit;
      n /= 10;
    }
    return squaresOfDigits;
  }

  public static boolean isHappy(int n) {
    if (n == 1) {
      return true;
    }

    int slow = n;
    int fast = n;

    while (fast != 1) {
      slow = sumOfSquares(slow);
      fast = sumOfSquares(sumOfSquares(fast));

      if ((slow == fast) && (slow != 1)) {
        return false;
      }
    }

    return true;
  }
}
