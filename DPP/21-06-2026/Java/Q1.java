import java.util.Arrays;

public class Q1 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {1, 3, 5, 8, 12};
        int target = 10;
        int result = sol.closestPairToTarget(nums, target);
        
        System.out.println(result);
    }
}

class Solution {
    public int closestPairToTarget(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        int minDiff = Integer.MAX_VALUE;

        while (left < right) {
            int currentSum = nums[left] + nums[right];
            int absDiff = Math.abs(currentSum - target);

            if (absDiff < minDiff) {
                minDiff = absDiff;
            }

            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                break;
            }
        }

        return minDiff;
    }
}