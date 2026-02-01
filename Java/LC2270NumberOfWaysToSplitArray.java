public class LC2270NumberOfWaysToSplitArray{
    public static void main(String[] args){
        int nums[] = {2, 3, 1, 0};
        System.out.println(waysToSplitArray(nums));
    }

    public static int waysToSplitArray(int[] nums){
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }

        int countSplit = 0;
        int leftSum = 0;
        for(int i = 0; i < nums.length - 1; i++){
            leftSum += nums[i];

            int rightSum = totalSum - leftSum;
            if(leftSum >= rightSum){
                countSplit++;
            }
        }

        return countSplit;
    }
}