import java.util.Arrays;

public class LC1929ConcatenationOfArray{
    public static void main(String[] args){
        int arr1[] = {1, 2, 3};
        System.out.println(Arrays.toString(getConcatenation(arr1)));

        int arr2[] = {4, 5};
        System.out.println(Arrays.toString(getConcatenation(arr2)));
    }

    public static int[] getConcatenation(int[] nums){
        int n = nums.length;
        int [] ans =  new int[2 * n];

        for(int i = 0; i < n; i++){
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
}