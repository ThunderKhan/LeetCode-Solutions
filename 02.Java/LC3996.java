public class LC3996 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int start[] = {1, 1};
        int target[] = {2, 2};

        boolean result = sol.canReach(start, target);
        System.out.println(result);
    }
}

class Solution {
    public boolean canReach(int[] start, int[] target) {
        int startParity = (start[0] + start[1]) % 2;
        int targetParity = (target[0] + target[1]) % 2;

        return (startParity == targetParity);
    }
}