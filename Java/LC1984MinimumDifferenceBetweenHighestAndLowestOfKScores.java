import java.util.*;

public class LC1984MinimumDifferenceBetweenHighestAndLowestOfKScores {

    static int minimumDifference(int[] nums, int k) {
        if (k <= 1) {
            return 0;
        }

        Arrays.sort(nums);
        int n = nums.length;
        int left = 0;
        int right = k - 1;
        int minDiff = Integer.MAX_VALUE;

        while (right < n) {
            int currDiff = nums[right] - nums[left];

            if (currDiff < minDiff) {
                minDiff = currDiff;
            }

            left++;
            right++;
        }
        
        if (minDiff == Integer.MAX_VALUE) {
            return 0;
        }
        
        return minDiff;
    }

    static class Test {
        int[] nums;
        int k;
        int expected;
        String description;

        Test(int[] n, int k, int e, String d) {
            this.nums = n;
            this.k = k;
            this.expected = e;
            this.description = d;
        }
    }

    public static void main(String[] args) {
        List<Test> tests = Arrays.asList(
            new Test(new int[]{90}, 1, 0, "Single element"),
            new Test(new int[]{9,4,1,7}, 2, 2, "Example case"),
            new Test(new int[]{1,5,9}, 3, 8, "k equals array length"),
            new Test(new int[]{5,5,5,5}, 3, 0, "All values equal"),
            new Test(new int[]{1,2,3,4,5}, 3, 2, "Already sorted increasing"),
            new Test(new int[]{8,1,2,2,3}, 3, 1, "Duplicates present"),
            new Test(new int[]{0,0,10,10}, 2, 0, "Zeros included"),
            new Test(new int[]{5,100,3}, 1, 0, "k = 1 always zero"),
            new Test(new int[]{1,100000,50000,50001}, 2, 1, "Large numeric gap"),
            new Test(new int[]{1,2}, 2, 1, "Minimum valid size"),
            new Test(new int[]{1,3,6,10,15}, 2, 2, "Increasing gaps"),
            new Test(new int[]{4,7,9,1,2}, 4, 6, "Window selection matters"),
            new Test(new int[]{5,5,5,5,100}, 4, 0, "Outlier should be ignored"),
            new Test(new int[]{10,1,9,2,8,3}, 3, 2, "Alternating values")
        );

        int passed = 0;

        for (int i = 0; i < tests.size(); i++) {
            try {
                Test t = tests.get(i);
                int actual = minimumDifference(t.nums.clone(), t.k);

                if (actual == t.expected) {
                    System.out.println("✅ PASS | Test " + (i+1) + ": " + t.description);
                    passed++;
                } else {
                    System.out.println("❌ FAIL | Test " + (i+1) + ": " + t.description);
                    System.out.println("   Expected: " + t.expected + ", Actual: " + actual);
                }
            } catch (Exception e) {
                System.out.println("❌ ERROR | Test " + (i+1) + ": " + tests.get(i).description);
            }
        }

        System.out.println("\nSummary:");
        if (passed == tests.size())
            System.out.println("🎉 All tests passed! (" + passed + "/" + tests.size() + ")");
        else
            System.out.println("⚠️ " + passed + "/" + tests.size() + " tests passed");
    }
}