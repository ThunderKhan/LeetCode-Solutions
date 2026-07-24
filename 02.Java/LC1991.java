public class LC1991 {
    public static void main(String[] args) {
        
    }
}

class Solution {
    public int findMiddleIndex(int[] nums) {
        int totalSum = 0;
        for (int i = 0; i < nums.length; i++) {
            totalSum += nums[i];
        }
        int left = 0;

        for (int i = 0; i < nums.length; i++) {
            int right = totalSum - left - nums[i];

            if (right == left) {
                return i;
            }

            left += nums[i];
        }

        return -1;
    }
}