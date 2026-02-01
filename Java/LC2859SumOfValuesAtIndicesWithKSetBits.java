import java.util.*;

public class LC2859SumOfValuesAtIndicesWithKSetBits{
    public static void main(String[] args){
        List<Integer> nums = Arrays.asList(5, 10, 1, 5, 2);
        int k = 1;
        System.out.println(sumIndicesWithKSetBits(nums, k));
    }

    public static int sumIndicesWithKSetBits(List<Integer> nums, int k){
        int n = nums.size();
        int[] setBits = new int[n];

        for(int i = 1; i < n; i++){
            setBits[i] = setBits[i >> 1] + (i & 1);
        }

        int total= 0;
        for(int j = 0; j < n; j++){
            if(setBits[j] == k){
                total += nums.get(j);
            }
        }

        return total;
    }
}