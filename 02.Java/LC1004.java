import java.util.Arrays;

public class LC1004 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
        int k = 2;

        int result = sol.longestOnes(nums, k);
        System.out.println(result);
    }
}

class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;

        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0)  {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }

                left++;
            }

            int currLen = right - left + 1;
            maxLen = Math.max(maxLen, currLen);
        }

        return maxLen;
    }
}