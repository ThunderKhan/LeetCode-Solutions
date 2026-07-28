import java.util.Map;
import java.util.HashMap;

public class LC0974 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {4, 5, 0, -2, -3, 1};
        int k = 5;

        int result = sol.subarraysDivByK(nums, k);
        System.out.println(result);
    }
}

class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        int runningSum = 0;
        int count = 0;

        for (int i = 0; i < nums.length; i++) {
            runningSum += nums[i];
            int rem = runningSum % k;

            if (rem < 0) {
                rem += k;
            }

            count += map.getOrDefault(rem, 0);
            map.put(rem, map.getOrDefault(rem, 0) + 1);
        }

        return count;
    }
}