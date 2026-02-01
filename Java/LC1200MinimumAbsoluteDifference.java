import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public class LC1200MinimumAbsoluteDifference {
    public static void main(String[] args) {
        int[] arr = {4, 2, 1, 3};
        System.out.println(minimumAbsDifference(arr));
    }

    public static List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        List<List<Integer>> result = new ArrayList<>();

        int minDiff = Integer.MAX_VALUE;
        for (int i = 0; i < (n - 1); i++) {
            int currDiff = arr[i + 1] - arr[i];
            List<Integer> pair = new ArrayList<>();

            if (currDiff < minDiff) {
                minDiff = currDiff;
                result.clear();
                pair.add(arr[i]);
                pair.add(arr[i + 1]);
                result.add(pair);
            } else if (currDiff == minDiff) {
                pair.add(arr[i]);
                pair.add(arr[i + 1]);
                result.add(pair);
            }
        }

        return result;
    }
}
