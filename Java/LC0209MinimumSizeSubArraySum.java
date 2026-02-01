public class LC0209MinimumSizeSubArraySum{
    public static void main(String[] args){
        int[] nums = {2, 3, 1, 2, 4, 3};
        int target = 7;

        int result = minSubArrayLen(nums, target);
        System.out.println(result);
    }

    public static int minSubArrayLen(int[] nums, int target){
        int n = nums.length;
        int low = 0;
        int windowSum = 0;
        int minLen = Integer.MAX_VALUE;

        for (int high = 0; high < n; high++) {
            windowSum += nums[high];

            while (windowSum >= target) {
                int length = high - low + 1;
                if (length < minLen) {
                    minLen = length;
                }
                windowSum -= nums[low];
                low++;
            }
        }

        if (minLen == Integer.MAX_VALUE){
            return 0;
        } else {
            return minLen;
        }
    }
}