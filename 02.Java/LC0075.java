import java.util.Arrays;

public class LC0075 {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {2, 0, 2, 1, 1, 0};
        
        sol.sortColors(nums);
        System.out.println(Arrays.toString(nums));
    }
}

class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                int temp = nums[mid];
                nums[mid] = nums[low];
                nums[low] = temp;

                mid++;
                low++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                int temp  = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;

                high--;
            }
        }
    }
}