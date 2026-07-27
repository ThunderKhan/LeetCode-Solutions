import java.util.Map;
import java.util.HashMap;

public class LC0560 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {1, 1, 1};
        int k = 2;

        int result = sol.subarraySum(nums, k);
        System.out.println(result);
    }
}

class Solution {
    int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        int count = 0;
        int runningSum = 0;

        for (int i = 0; i < nums.length; i++) {
            runningSum += nums[i];
            int diff = runningSum - k;

            if (map.containsKey(diff)) {
                count += map.get(diff);
            }

            map.put(runningSum, map.getOrDefault(runningSum, 0) + 1);
        }

        return count;
    }
}