public class LC0152 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int nums[] = {2, 3, -2, 4};
        int result = sol.maxProduct(nums);

        System.out.println(result);
    }
}

class Solution {
    public int maxProduct(int[] nums) {
        int maxProductEndingHere = nums[0];
        int minProductEndingHere = nums[0];
        int maximumProduct = nums[0];

        for (int i = 1; i < nums.length; i++) {
            int current = nums[i];

            int prevMax = maxProductEndingHere;
            int prevMin = minProductEndingHere;

            maxProductEndingHere = Math.max(
                current,
                Math.max(
                    current * prevMax,
                    current * prevMin
                )
            );
            
            minProductEndingHere = Math.min(
                current,
                Math.min(
                    current * prevMax,
                    current * prevMin
                )
            );

            maximumProduct = Math.max(maximumProduct, maxProductEndingHere);
        }

        return maximumProduct;
    }
}