import java.util.Arrays;

public class LC0016 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {-1, 2, 1, -4};
        int target = 1;

        int result = sol.threeSumClosest(nums, target);
        System.out.println(result);
    }
}

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;

        int closestSum = 0;
        int closestDiff = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];
                int currDiff = Math.abs(currSum - target);

                if (currDiff < closestDiff) {
                    closestDiff = currDiff;
                    closestSum = currSum;
                }

                if (currSum < target) {
                    left++;
                } else if (currSum > target) {
                    right--;
                } else {
                    return currSum;
                }
            }
        }
        return closestSum;
    }
}