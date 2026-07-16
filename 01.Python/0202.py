class Solution:
    def squareSum(self, n: int) -> int:
        sumOfSquares = 0

        while (n):
            digit = n % 10
            sumOfSquares += digit * digit
            n //= 10

        return sumOfSquares


    def isHappy(self, n: int) -> bool:
        if (n == 1):
            return True
        
        slow = n
        fast = n

        while (fast != 1):
            slow = self.squareSum(slow)
            fast = self.squareSum(self.squareSum(fast))

            if (slow == fast and slow != 1):
                return False

        return True

sol = Solution()

n1 = 19
print(sol.isHappy(n1))

n2 = 2
print(sol.isHappy(n2))
