import java.util.Arrays;

public class LC3788MaximumScoreOfASplit {

    public static int maximumScore(int[] nums) {
        int n = nums.length;

        int[] prefixSum = new int[n];
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int[] suffixMin = new int[n];
        Arrays.fill(suffixMin, Integer.MAX_VALUE);

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] < suffixMin[i + 1]) {
                suffixMin[i] = nums[i + 1];
            } else {
                suffixMin[i] = suffixMin[i + 1];
            }
        }

        int maxScore = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            int score = prefixSum[i] - suffixMin[i];
            if (score > maxScore) {
                maxScore = score;
            }
        }

        return maxScore;
    }

    public static void main(String[] args) {
        int[] nums = {10, -1, 3, -4, -5};
        System.out.println(maximumScore(nums));
    }
}
