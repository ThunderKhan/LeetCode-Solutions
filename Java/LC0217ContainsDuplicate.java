import java.util.HashSet;
import java.util.Set;

public class LC0217ContainsDuplicate{
    public static void main(String[] args){
        int nums[] = {1, 2, 3, 3};
        System.out.println(containsDuplicate(nums));
    }

    public static boolean containsDuplicate(int[] nums){
        Set<Integer> seen = new HashSet<>();

        for(int num : nums){
            if (seen.contains(num)){
                return true;
            }
            seen.add(num);
        }
        return false;
    }

}