public class LC1800 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {10, 20, 30, 5, 10, 50};
        int result = sol.maxAscendingSum(nums);

        System.out.println(result);
    }
}

class Solution {
    public int maxAscendingSum(int[] nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            } else {
                currentSum = nums[i];
            }

            maxSum = Math.max(maxSum, currentSum);
        }

        return maxSum;
    }
}