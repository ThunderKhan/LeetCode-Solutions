import java.util.Arrays;
import java.util.ArrayList;

public class LC2574LeftAndRightSumDifference {
    public static void main(String[] args) {
        int[] nums = {10, 4, 8, 3};
        System.out.println(Array.toString(leftRightDifference(nums)));
    }

    public static int[] leftRightDifference(int[] nums){
        int leftSum = 0;
        int rightSum = 0;

        for(int num : nums){
            rightSum += num;
        }

        ArrayList<Integer> temp = new ArrayList<>();
        for(int num : nums){
            leftSum += num;
            tenp.add(Math.abs(leftSum - rightSum));
            rightSum -= num;
        }

        int[] answer = new int[temp.size()];
        for(int i = 0; i < temp.size(); i++){
            answer[i] = temp.get(i);
        }

        return answer;
    }
}
