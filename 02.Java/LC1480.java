import java.util.Arrays;

public class LC1480 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {1, 2, 3, 4};
        int[] result = sol.runningSum(nums);

        System.out.println(Arrays.toString(result));
    }
}

class Solution {
    public int[] runningSum(int[] nums) {
        int n = nums.length;
        
        int[] ans = new int[n];
        Arrays.fill(ans, 0);
        ans[0] = nums[0];

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + nums[i];
        }

        return ans;
    }
}