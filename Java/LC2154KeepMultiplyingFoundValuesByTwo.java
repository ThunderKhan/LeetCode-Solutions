import java.util.HashSet;

public class LC2154KeepMultiplyingFoundValuesByTwo{
    public static void main(String[] args){
        int[] nums = {5, 3, 6, 1, 12};
        int original = 3;
        int result = findFinalValue(nums, original);

        System.out.println(result);
    }

    public static int findFinalValue(int[] nums, int original){
        HashSet<Integer> seen = new HashSet<>();
        for(int num : nums){
            seen.add(num);
        }

        while(true){
            if(!seen.contains(original)){
                break;
            } else{
                original *= 2;
                if(original == 0){
                    return 0;
                }
            }
        }

        return original;
    }
}