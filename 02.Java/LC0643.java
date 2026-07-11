import java.util.Arrays;

public class LC0643 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {1, 12, -5, -6, 50, 3};
        int k = 4;

        double result = sol.findMaxAverage(nums, k);
        System.out.println(result);
    }
}

class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        
        if (k > n) {
            return -1.0f;
        }

        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;
        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i - k];

            if (maxSum < windowSum) {
                maxSum = windowSum;
            }
        }
        double maxAvg = (double) maxSum / k;
        return maxAvg;
    }
}