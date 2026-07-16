public class LC0202 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int n1 = 19;
        System.out.println(sol.isHappy(n1));
        
        int n2 = 2;
        System.out.println(sol.isHappy(n2));
    }
}

class Solution {
    private int squareSum(int n) {
        int sumOfSquares = 0;

        while (n > 0) {
            int digit = n % 10;
            sumOfSquares += digit * digit;
            n /= 10;
        }

        return sumOfSquares;
    }

    public boolean isHappy(int n) {
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
}