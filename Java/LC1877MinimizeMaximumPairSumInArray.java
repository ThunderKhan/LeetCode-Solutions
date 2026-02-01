import java.util.*;

public class LC1877MinimizeMaximumPairSumInArray {

    public static int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int left = 0;
        int right = nums.length - 1;
        int maxSum = Integer.MIN_VALUE;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum > maxSum) {
                maxSum = sum;
            }

            left++;
            right--;
        }

        return maxSum;
    }

    static class Test {
        int[] nums;
        int expected;
        String description;

        Test(int[] n, int e, String d) {
            nums = n;
            expected = e;
            description = d;
        }
    }

    public static void main(String[] args) {

        List<Test> tests = List.of(
            new Test(new int[]{3,5,2,3}, 7, "Given example 1"),
            new Test(new int[]{3,5,4,2,4,6}, 8, "Given example 2"),
            new Test(new int[]{1,1}, 2, "Minimum size"),
            new Test(new int[]{1,100000}, 100001, "Extreme values"),
            new Test(new int[]{5,5,5,5}, 10, "All equal"),
            new Test(new int[]{1,2,3,4}, 5, "Perfect symmetry"),
            new Test(new int[]{1,2,3,100}, 101, "One dominant large"),
            new Test(new int[]{10,1,9,2,8,3}, 11, "Random order"),
            new Test(new int[]{1,1,1,100,100,100}, 101, "Many duplicates"),
            new Test(new int[]{2,2,2,3}, 5, "Unbalanced duplicates"),
            new Test(new int[]{7,3,5,1}, 8, "Reverse order"),
            new Test(new int[]{1,50,50,50,50,1}, 100, "Heavy middle"),
            new Test(new int[]{4,4,4,4,4,4}, 8, "All identical"),
            new Test(new int[]{1,2,2,2,9,10}, 11, "Clustered values"),
            new Test(new int[]{100000,1,99999,2}, 100001, "Large boundary sums")
        );

        int passed = 0;

        for (int i = 0; i < tests.size(); i++) {
            Test t = tests.get(i);
            int actual = minPairSum(t.nums);

            if (actual == t.expected) {
                System.out.println("✅ PASS | Test " + (i+1) + ": " + t.description);
                passed++;
            } else {
                System.out.println("❌ FAIL | Test " + (i+1) + ": " + t.description);
                System.out.println("   Expected: " + t.expected + ", Actual: " + actual);
            }
        }

        if (passed == tests.size())
            System.out.println("\n🎉 All tests passed! (" + passed + "/" + tests.size() + ")");
        else
            System.out.println("\n⚠️ " + passed + "/" + tests.size() + " tests passed");
    }
}
