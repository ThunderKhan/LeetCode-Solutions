public class LC0747LargestNumberAtLeastTwiceOfOthers{
    public static void main(String[] args){
        int[] nums = {3, 6, 1, 0};
        int result = dominantIndex(nums);

        System.out.println(result);
    }

    public static int dominantIndex(int[] nums){
        int largest = nums[0];
        int largestIdx = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] > largest){
                largest = nums[i];
                largestIdx = i;
            }
        }

        for(int i = 0; i < nums.length; i++){
            if(nums[i] == largest){
                continue;
            }

            if((2 * nums[i]) > largest){
                return -1;
            }
        }

        return largestIdx;
    }
}