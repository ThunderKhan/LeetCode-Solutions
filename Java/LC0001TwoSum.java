import java.util.HashMap;
import java.util.Arrays;

public class LC0001TwoSum{
    public static void main(String[] args) {
        int[] arr1 = {1, 2};
        int target1 = 3;
        System.out.println(Arrays.toString(twoSum(arr1, target1)));


        int [] arr2 = {3, 3};
        int target2 = 6;
        System.out.println(Arrays.toString(twoSum(arr2, target2)));


        int[] arr3 = {-1, 4, 2};
        int target3 = 1;
        System.out.println(Arrays.toString(twoSum(arr3, target3)));

    }

    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for(int i = 0; i < nums.length; i++){
            int complement = target - nums[i];

            if(map.containsKey(complement)){
                return new int[] {map.get(complement), i};
            }
            
            map.put(nums[i], i);
        }

        return new int[] {};
    }
}