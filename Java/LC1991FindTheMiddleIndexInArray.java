public class LC1991FindTheMiddleIndexInArray{
    public static void main(String[] args){
        int[] nums = {2, 3, -1, 8, 4};
        System.out.println(findMiddleIndex(nums));
    }
    
    public static int findMiddleIndex(int[] nums){
        int totalSum = 0;
        for(int num : nums){
            totalSum += nums;
        }

        int leftSum = 0;
        for(int i = 0; i < nums.length; i++){
            int rightSum = totalSum - leftSum - nums[i];

            if(rightSum == leftSum){
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
}