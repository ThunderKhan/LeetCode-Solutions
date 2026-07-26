public class LC0628 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {1, 2, 3, 4};
        int result = sol.maximumProduct(nums);

        System.err.println(result);
    }
}

class Solution {
    public int maximumProduct(int[] nums) {
        int max1 = -10000, max2 = -10000, max3 = -10000;
        int min1 = 10000, min2 = 10000;

        for (int num : nums) {
            if (num >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num >= max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }

            if (num <= min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }

        return Math.max(max1 * max2 * max3, max1 * min1 * min2);
    }
}