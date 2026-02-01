import java.util.Arrays;
import java.util.HashMap;
import java.util.ArrayList;

public class LC0350IntersectionOfTwoArraysII{
    public static void main(String[] args){
        int[] nums1 = {4, 9, 5, 9, 4};
        int[] nums2 = {4, 5, 9, 7};

        int[] result = intersection(nums1, nums2);
        System.out.println(Arrays.toString(result));
    }

    public static int[] intersection(int[] nums1, int[] nums2){
        int[] large;
        int[] small;

        if(nums1.length > nums2.length){
            large = nums1;
            small = nums2;
        } else{
            large = nums2;
            small = nums1;
        }

        HashMap<Integer, Integer> frequencyMap = new HashMap<>();
        for(int num : small){
            if(frequencyMap.containsKey(num)){
                frequencyMap.put(num, frequencyMap.get(num) + 1);
            } else{
                frequencyMap.put(num, 1);
            }
        }

        ArrayList<Integer> temp = new ArrayList<>();
        for(int num : large){
            if(frequencyMap.containsKey(num) && frequencyMap.get(num) > 0){
                temp.add(num);
                frequencyMap.put(num, frequencyMap.get(num) - 1);
            }
        }

        int[] result = new int[temp.size()];
        for(int i = 0; i < temp.size(); i++){
            result[i] = temp.get(i);
        }

        return result;
    }
}