import java.util.HashSet;
import java.util.ArrayList;
import java.util.Arrays;

public class LC0349IntersectionOfTwoArrays{
    public static void main(String[] args){
        int[] nums1 = {1, 2, 2, 1};
        int[] nums2 = {2 , 2};

        int[] result = intersection(nums1, nums2);
        System.out.println(Arrays.toString(result));
    }

    public static int[] intersection(int[] nums1, int[] nums2){
        HashSet<Integer> seen = new HashSet<>();
        ArrayList<Integer> temp = new ArrayList<>();

        for(int num : nums1){
            seen.add(num);
        }

        for(int num : nums2){
            if(seen.contains(num)){
                temp.add(num);
                seen.remove(num);
            }
        }

        int[] result = new int[temp.size()];
        for(int i = 0; i < temp.size(); i++){
            result[i] = temp.get(i);
        }

        return result;
    }
}