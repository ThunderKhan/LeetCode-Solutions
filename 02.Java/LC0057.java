import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class LC0057 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[][] intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
        int[] newInterval = {4, 8};

        int[][] result = sol.insert(intervals, newInterval);
        System.out.println(Arrays.deepToString(result));
    }
}

class Solution {
    public int[][] merge(int[][] intervals) {
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

    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> temp = new ArrayList<>();

        boolean inserted = false;
        for (int i = 0; i < intervals.length; i++) {
            int currStart = intervals[i][0];

            if (!inserted && (currStart >= newInterval[0])) {
                temp.add(newInterval);
                inserted = true;
            }

            temp.add(intervals[i]);
        }

        if (!inserted) {
            temp.add(newInterval);
        }

        int[][] result = temp.toArray(new int[temp.size()][]);
        result = merge(result);
        
        return result;
    }
}