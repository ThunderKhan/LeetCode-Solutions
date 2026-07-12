class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)

        left = 0
        maxLen = 0
        seenChar = set()

        for right in range(n):
            current = s[right]

            while current in seenChar:
                seenChar.remove(s[left])
                left += 1

            seenChar.add(current)
            
            currLen = right - left + 1
            if currLen > maxLen:
                maxLen = currLen
        
        return maxLen

sol = Solution()

s = "abcabcbb"
print(sol.lengthOfLongestSubstring(s))