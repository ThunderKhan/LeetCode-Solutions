import java.util.ArrayList;

public class LC0448FindAllNumbersDisappearedInAnArray {
    public static void main(String[] args) {
        
    }

    public static List<Integer> findDisappearedNumber(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            int val = Math.abs(nums[i]);
            int idx = val - 1;

            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        List<Integer> missing = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                missing.add(i + 1);
            }
        }

        return missing;
    }
}