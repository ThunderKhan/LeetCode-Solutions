class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = {}

        for char in t:
            need[char] = need.get(char, 0) + 1

        required = len(t)

        left = 0
        minLen = float('inf')
        start = 0

        for right in range(len(s)):
            if (need.get(s[right], 0) > 0):
                required -= 1
            
            need[s[right]] = need.get(s[right], 0) - 1

            while required == 0:

                if right - left + 1 < minLen:
                    minLen = right - left + 1
                    start = left
                
                need[s[left]] = need.get(s[left], 0) + 1

                if need[s[left]] > 0:
                    required += 1
                
                left += 1

        if minLen == float('inf'):
            return ""

        return s[start:start + minLen]

sol = Solution()

s = "ADOBECODEBANC"
t = "ABC"

result = sol.minWindow(s, t)
print(result)