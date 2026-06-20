import java.util.Arrays;

public class LC0167 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] result = sol.twoSum(nums, target);
        System.out.println("Test 1: " + Arrays.toString(result));
    }
}

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0;
        int right = numbers.length - 1;

        while (left < right) {
            int currentSum = numbers[left] + numbers[right];

            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                return new int[]{left + 1, right + 1};
            }
        }

        return new int[]{-1, -1};
    }
}