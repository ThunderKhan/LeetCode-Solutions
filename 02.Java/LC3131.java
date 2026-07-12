import java.util.Arrays;

public class LC3131 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums1 = {2, 6, 4};
        int[] nums2 = {9, 7, 5};

        System.out.println(sol.addedInteger(nums1, nums2));
    }
}

class Solution {
    public int addedInteger(int[] nums1, int[] nums2) {
        int x1 = Arrays.stream(nums1).min().getAsInt();
        int x2 = Arrays.stream(nums2).min().getAsInt();

        return x2 - x1;
    }
}