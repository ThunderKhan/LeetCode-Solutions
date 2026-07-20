class LC1749 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {1, -3, 2, 3, -4};
        int result = sol.maxAbsoluteSum(nums);

        System.out.println(result);
    }
}

class Solution {
    int maxAbsoluteSum(int[] nums) {
        int maxPosSum = nums[0];
        int maxNegSum = nums[0];
        int absMaxSum = Math.abs(nums[0]);

        for (int i = 1; i < nums.length; i++) {
            maxPosSum = Math.max(nums[i], nums[i] + maxPosSum);
            maxNegSum = Math.min(nums[i], nums[i] + maxNegSum);

            absMaxSum = Math.max(absMaxSum, Math.max(Math.abs(maxPosSum), Math.abs(maxNegSum)));
        }

        return absMaxSum;
    }
}