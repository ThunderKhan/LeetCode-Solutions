import java.util.Arrays;

public class LC2903FindIndicesWithIndexAndValueDifferenceI{
    public static void main(String[] args){
        int[] nums = {5, 1, 4, 1};
        int indexDifference = 2; 
        int valueDifference = 4;

        int[] result = findIndices(nums, indexDifference, valueDifference);
        System.out.println(Arrays.toString(result));
    }

    public static int[] findIndices(int[] nums, int indexDifference, int valueDifference){
        int n = nums.length;
        int[] defaultResult = {-1, -1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(Math.abs(i - j) >= indexDifference){
                    if(Math.abs(nums[i] - nums[j]) >= valueDifference){
                        int[] result = {i, j};
                        return result;
                    }
                }
            }
        }

        return defaultResult;
    }
}