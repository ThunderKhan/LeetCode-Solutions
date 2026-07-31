import java.util.HashMap;
import java.util.Map;

public class LC0525 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {0, 1, 1, 1, 1, 1, 0, 0, 0};
        int result = sol.findMaxLength(nums);

        System.out.println(result);
    }
}

class Solution {
    int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        
        int maxLen = 0;
        int runningSum = 0;

        for(int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                runningSum -= 1;
            } else {
                runningSum += 1;
            }

            if (map.containsKey(runningSum)) {
                int currLen = i - map.get(runningSum);
                maxLen = Math.max(maxLen, currLen);
            } else {
                map.put(runningSum, i);
            }
        }

        return maxLen;
    }
}