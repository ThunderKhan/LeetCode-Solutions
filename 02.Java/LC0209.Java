import java.util.Arrays;

public class LC0209 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int target = 7;
        int[] nums = {2, 3, 1, 2, 4, 3};

        System.out.println(sol.minSubArrayLen(target, nums));
    }
}

class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;

        int left = 0;
        int windowSum = 0;
        int minLen = Integer.MAX_VALUE;

        for (int right = 0; right < n; right++) {
            windowSum += nums[right];

            while (windowSum >= target)  {
                int currLen = right - left + 1;
                if (currLen < minLen) {
                    minLen = currLen;
                }

                windowSum -= nums[left];
                left++;
            }
        }

        if (minLen == Integer.MAX_VALUE) {
                return 0;
        } else {
            return minLen;
        }
    }
}