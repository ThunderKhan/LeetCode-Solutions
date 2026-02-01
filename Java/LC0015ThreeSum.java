import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public class LC0015ThreeSum{
    public static void main(String[] args){
        int[] nums = {-1, 0, 1, 2, -1, 4};
        System.out.println(threeSum(nums));
    }

    public static List<List<Integer>> threeSum(int[] nums){
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        Arrays.sort(nums);

        for(int i = 0; i < n - 2; i++){
            if(nums[i] > 0){
                break;
            }

            if((i > 0) && nums[i] == nums[i - 1]){
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum > 0){
                    right--;
                } else if(sum < 0){
                    left++;
                } else{
                    ArrayList<Integer> triplet = new ArrayList<>();
                    triplet.add(nums[i]);
                    triplet.add(nums[left]);
                    triplet.add(nums[right]);

                    result.add(triplet);

                    left++;
                    right--;

                    while((left < right) && (nums[left] == nums[left - 1])){
                        left++;
                    }

                    while((left < right) && (nums[right] == nums[right + 1])){
                        right--;
                    }
                }
            }
        }

        return result;
    }
}