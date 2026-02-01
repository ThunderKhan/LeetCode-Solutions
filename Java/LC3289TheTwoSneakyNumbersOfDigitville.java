import java.util.Arrays;
import java.util.HashSet;
import java.util.ArrayList;

public class LC3289TheTwoSneakyNumbersOfDigitville{
    public static void main(String[] args){
        int[] nums = {0, 1, 1, 0};
        System.out.println(Arrays.toString(getSneakyNumber(nums)));
    }

    public static int[] getSneakyNumber(int[] nums){
        HashSet<Integer> seen = new HashSet<>();
        ArrayList<Integer> temp = new ArrayList<>();

        for(int num : nums){
            if(seen.contains(num)){
                temp.add(num);
            }else{
                seen.add(num);
            }
        }

        int[] ans = new int[temp.size()];
        for(int i = 0; i < temp.size(); i++){
            ans[i] = temp.get(i);
        }

        return ans;
    }
}