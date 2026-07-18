public class LC0053 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.err.println(sol.maxSubArray(nums));
    }
}

class Solution {
    public int maxSubArray(int[] nums) {
        int bestLocalSum = nums[0];
        int bestGlobalSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            bestLocalSum = Math.max(nums[i], nums[i] + bestLocalSum);
            bestGlobalSum = Math.max(bestLocalSum, bestGlobalSum);
        }

        return bestGlobalSum;
    }
}