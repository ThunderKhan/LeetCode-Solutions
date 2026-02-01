import java.util.Arrays;

public class LC0167TwoSumII{
    public static void main(String[] args){
        int[] numbers = {2, 7, 11, 15};
        int target = 9;
        System.out.println(Arrays.toString(twoSum(numbers, target)));
    }

    public static int[] twoSum(int[] numbers, int target){
        int n = numbers.length;
        int left = 0;
        int right = n - 1;

        while(left < right){
            int sum = numbers[left] + numbers[right];

            if(sum > target){
                right--;
            } else if(sum < target){
                left++;
            } else{
                return new int[] {left + 1, right + 1};
            }
        }

        return new int[0];
    }
}