import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public class LC0986 {
    public static void main(String[] args) {
        Solution sol = new Solution();
        
        int[][] firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
        int[][] secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

        int[][] result = sol.intervalIntersection(firstList, secondList);
        System.out.println(Arrays.deepToString(result));
    }
}

class Solution {
    int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        List<int[]> temp = new ArrayList<>();

        int i = 0;
        int j = 0;

        while ((i < firstList.length) && (j < secondList.length)) {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            if ((Math.max(start1, start2)) <= (Math.min(end1, end2))) {
                temp.add(new int[]{(Math.max(start1, start2)), (Math.min(end1, end2))});
            }

            if (end1 <= end2) {
                i++;
            } else {
                j++;
            }
        }

        int[][] result = temp.toArray(new int[temp.size()][]);
        return result;
    }
}