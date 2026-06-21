import java.util.Arrays;

public class LC0026 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {1, 1, 1, 2, 2, 3};
        int result = sol.removeDuplicates(nums);
        System.out.println("Test 1: " +  result + ", " + Arrays.toString(nums));
    }
}

class Solution {
    public int removeDuplicates(int[] nums) {
        int low = 0;
        int high = 1;
        int uniqueCount = 1;
        int n = nums.length;

        while (high < n) {
            if (nums[high] == nums[high - 1]) {
                high++;
                continue;
            }

            nums[low + 1] = nums[high];
            low++;
            high++;
            uniqueCount++;
        }

        return uniqueCount;
    }
}