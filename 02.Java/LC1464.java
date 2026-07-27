public class LC1464 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {2, 3, 4, 5};
        int result = sol.maxProduct(nums);

        System.out.println(result);
    }
}

class Solution {
    public int maxProduct(int[] nums) {
        int max1 = 0, max2 = 0;

        for (int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
        }

        return ((max1 - 1 ) * (max2 - 1));
    }
}