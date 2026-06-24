import java.util.Arrays;

public class LC0977 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {-7, -3, 2, 3, 11};
        int[] result = sol.sortedSquares(nums);

        System.out.println(Arrays.toString(result));
    }
}

class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];

        int left = 0;
        int right = n - 1;
        int write = n - 1;

        while (left <= right) {
            if (Math.abs(nums[left]) > Math.abs(nums[right])) {
                result[write] = nums[left] * nums[left];
                left++;
            } else {
                result[write] = nums[right] * nums[right];
                right--;
            }

            write--;
        }

        return result;
    }
}