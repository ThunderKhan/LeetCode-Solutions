import java.util.HashSet;

public class LC0961NRepeatedElementsInSize2NArray{
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 3};
        System.out.println(repeatedNTimes(nums));
    }

    public static int repeatedNTimes(int[] nums){
        HashSet<Integer> seen = new HashSet<>();

        for(int num : nums){
            if(seen.contains(num)){
                return num;
            }else{
                seen.add(num);
            }
        }

        return -1;
    }
}