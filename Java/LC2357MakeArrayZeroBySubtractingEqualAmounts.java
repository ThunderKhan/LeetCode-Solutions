import java.util.HashSet;

public class LC2357MakeArrayZeroBySubtractingEqualAmounts{
    public static void main(String[] args) {
        int[] nums = {1, 5, 0, 3, 5};
        int result = minimumOperations(nums);

        System.out.print("\nThe minimum number of operations required to make the array zero is: ");
        System.out.println(result);
    }

    public static int minimumOperations(int[] nums) {
        HashSet<Integer> seen = new HashSet<>();
        int nonZeroCount = 0;

        for (int i = 0; i < nums.length; i++) {
            if ((nums[i] != 0) && (!seen.contains(nums[i]))) {
                nonZeroCount++;
                seen.add(nums[i]);
            }
        }

        return nonZeroCount;
    }
}