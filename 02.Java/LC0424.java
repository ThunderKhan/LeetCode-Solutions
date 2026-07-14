public class LC0424 {
    public static void main(String[] args) {
        Solution sol = new Solution();
        
        String s = "ABAB";
        int k = 2;

        int result = sol.characterReplacement(s, k);
        System.out.println(result);
    }
}

class Solution {
    public int characterReplacement(String s, int k) {
        int n = s.length();

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        int[] freq = new int[26];

        for (int right = 0; right < n; right++) {
            int idx = s.charAt(right) - 'A';
            freq[idx]++;
            maxFreq = Math.max(maxFreq, freq[idx]);

            while (((right - left + 1) - maxFreq) > k) {
                int idxL = s.charAt(left) - 'A';
                freq[idxL]--;
                left++;
            }

            ans = Math.max(ans, (right - left + 1));
        }

        return ans;
    }
}