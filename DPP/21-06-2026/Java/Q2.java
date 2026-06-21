import java.util.Arrays;

public class Q2 {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1, 2, 3, 4};
        int target = 6;
        int result = sol.numberOfSmallerPairs(nums, target);

        System.out.println(result);
    }
}

class Solution {
    public int numberOfSmallerPairs(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        int count = 0;

        while (left < right) {
            int currentSum = nums[left] + nums[right];
            
            if (currentSum < target) {
                count += (right - left);
                left += 1;
            } else {
                right -= 1;
            }
        }

        return count;
    }
}