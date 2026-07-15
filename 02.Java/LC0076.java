import java.util.HashMap;
import java.util.Map;

public class LC0076 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        String s = "ADOBECODEBANC";
        String t = "ABC";

        String result = sol.minWindow(s, t);
        System.out.println(result);
    }
}


class Solution {
    public String minWindow(String s, String t) {

        Map<Character, Integer> need = new HashMap<>();

        for (char c : t.toCharArray()) {
            need.put(c, need.getOrDefault(c, 0) + 1);
        }

        int required = t.length();

        int left = 0;
        int minLen = Integer.MAX_VALUE;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {

            if (need.getOrDefault(s.charAt(right), 0) > 0) {
                required--;
            }

            // Add current character into the window
            need.put(
                s.charAt(right),
                need.getOrDefault(s.charAt(right), 0) - 1
            );


            while (required == 0) {

                // Update smallest valid window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                need.put(
                    s.charAt(left),
                    need.getOrDefault(s.charAt(left), 0) + 1
                );

                if (need.get(s.charAt(left)) > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLen == Integer.MAX_VALUE) {
            return "";
        }

        return s.substring(start, start + minLen);
    }
}