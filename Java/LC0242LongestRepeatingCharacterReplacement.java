public class LC0242LongestRepeatingCharacterReplacement {
    public static void main(String[] args) {
       String s = "ABAB";
       int k = 2;
       System.out.println(characterReplacement(s, k));
    }

    public static int characterReplacement(String s, int k) {
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