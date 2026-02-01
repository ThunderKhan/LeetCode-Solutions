public class LC0643MaximumAverageSubarrayI {
    public static void main(String[] args) {
        int[] nums = {1, 12, -5, -6, 50, 3};
        int k = 4;

        float result = findMaxAverage(nums, k);
        System.out.println("The maximum average for a sub-array of size " + k + " is: " + result);
    }

    public static float findMaxAverage(int[] nums, int k) {
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

            if (windowSum > maxSum) {
                maxSum = windowSum;
            }
        }

        float maxAvg = (float) maxSum / k;
        return maxAvg;
    }
}
