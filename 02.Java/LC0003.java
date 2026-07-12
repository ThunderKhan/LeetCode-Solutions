import java.util.HashSet;

public class LC0003 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        String s = "abcabcbb";
        System.out.println(sol.lengthOfLongestSubstring(s));
    }
}

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();

        int left = 0;
        int maxLen = 0;
        HashSet<Character> seenChar = new HashSet<>();

        for (int right = 0; right < n; right++) {
            char current = s.charAt(right);

            while (seenChar.contains(current)) {
                seenChar.remove(s.charAt(left));
                left++;
            }

            seenChar.add(current);

            int currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
            }
        }

        return maxLen;
    }
}