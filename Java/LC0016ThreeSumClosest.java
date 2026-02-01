import java.util.Arrays;

public class LC0016ThreeSumClosest {
    public static void main(String[] args){
        int[] nums = {0, 0, 0};
        int target = 1;
        System.out.println(threeSumClosest(nums, target));
    }

    public static int threeSumClosest(int[] nums, int target){
        int n = nums.length;
        Arrays.sort(nums);

        int bestDiff = Integer.MAX_VALUE;
        int bestSum = 0;

        for(int i = 0; i < n - 2; i ++){
            int left = i + 1;
            int right = n - 1;

            while(left < right){
                int currSum = nums[i] + nums[left] + nums[right];
                int currDiff = Math.abs(currSum - target);

                if(currDiff < bestDiff){
                    bestDiff = currDiff;
                    bestSum = currSum;
                }

                if(currSum < target){
                    left++;
                } else if(currSum > target){
                    right--;
                } else{
                    return currSum;
                }
            }
        }

        return bestSum;
    }
}
