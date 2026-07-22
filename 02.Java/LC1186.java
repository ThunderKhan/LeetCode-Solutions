public class LC1186{
    public static void main(String[] args) {
        Solution sol = new Solution();

        int arr1[] = {1, -2, 0, 3};
        int arr2[] = {1, -2, -2, 3};
        int arr3[] = {-1, -1, -1, -1};

        int result1 = sol.maximumSum(arr1);
        int result2 = sol.maximumSum(arr2);
        int result3 = sol.maximumSum(arr3);

        System.out.println(result1);
        System.out.println(result2);
        System.out.println(result3);
    }
}

class Solution {
    public int maximumSum(int[] arr) {
        int noDelSum = arr[0];
        int oneDelSum = -10000;
        int result = arr[0];

        for (int i = 1; i < arr.length; i++) {
            int prevNoDel = noDelSum;

            noDelSum = Math.max(
                arr[i],
                arr[i] + noDelSum
            );

            oneDelSum = Math.max(
                prevNoDel,
                arr[i] + oneDelSum
            );

            result = Math.max(
                result,
                Math.max(noDelSum, oneDelSum)
            );
        }

        return result;
    }
}