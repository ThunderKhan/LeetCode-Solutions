import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public class LC0056 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[][] intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        int[][] result = sol.merge(intervals);

        System.out.println(Arrays.deepToString(result));
    }
}


class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(
            intervals,
            (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]
        );

        List<int[]> temp = new ArrayList<>();

        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currStart <= prevEnd) {
                prevEnd = Math.max(prevEnd, currEnd);
                continue;
            } else {
                temp.add(new int[]{prevStart, prevEnd});
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }

        temp.add(new int[]{prevStart, prevEnd});
        int[][] result = temp.toArray(new int[temp.size()][]);

        return result;
    }
}