public class LC0918 {
    public static void main(String[] args) {

    }
}

class Solution {
    public int maxSubaarySumCircular(int[] nums) {
        int localMax = nums[0];
        int globalMax = nums[0];

        int localMin = nums[0];
        int globalMin = nums[0];

        int totalSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            localMax = Math.max(nums[i], nums[i] + localMax);
            globalMax = Math.max(localMax, globalMax);

            localMin = Math.min(nums[i], nums[i] + localMin);
            globalMin = Math.min(localMin, globalMin);

            totalSum += nums[i];
        }

        if (globalMin == totalSum) {
            return globalMax;
        }

        int wrappingSum = totalSum - globalMin;
        int result = Math.max(wrappingSum, globalMax);

        return result;
    }
}