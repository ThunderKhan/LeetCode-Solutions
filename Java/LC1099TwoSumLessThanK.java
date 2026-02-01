import java.util.Arrays;

public class LC1099TwoSumLessThanK{
    public static void main(String[] args) {
        int[] nums = {34, 23, 1, 24, 75, 33, 54, 8};
        int k = 60;

        int result = twoSumLessThanK(nums, k);
        System.out.print("The maximum sum less than k in array is: ");
        System.out.println(result);
    }

    public static int twoSumLessThanK(int[] nums, int k){
        Arrays.sort(nums);
        int maxSum = Integer.MIN_VALUE;

        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int currSum = nums[left] + nums[right];
            if (currSum < k) {
                if (currSum > maxSum) {
                    maxSum = currSum;
                }
                left++;
            } else {
                right--;
            }
        }

        return maxSum;
    }
}