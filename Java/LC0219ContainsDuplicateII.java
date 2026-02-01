import java.util.HashSet;

public class LC0219ContainsDuplicateII{
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 1};
        int k = 3;
        System.out.println(containsNearbyDuplicate(nums, k));
    }

    public static boolean containsNearbyDuplicate(int[] nums, int k) {
        HashSet<Integer> seenWindow = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            if (seenWindow.contains(nums[i])) {
                return true;
            }
            seenWindow.add(nums[i]);

            if (seenWindow.size() > 3) {
                seenWindow.remove(nums[i - k]);
            }
        }
        return false;
    }
}