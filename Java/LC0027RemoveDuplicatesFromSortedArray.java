public class LC0026RemoveDuplicatesFromSortedArray{
    public static void main(String[] args){

    }

    public static int removeDuplicates(int[] nums){
        int low = 0;
        int high = 1;
        int uniqueCount = 1;

        while(high < nums.length){
            if(nums[high] == nums[high - 1]){
                high++;
                continue;
            }

            nums[low + 1] = nums[high];

            low++;
            high++;
            uniqueCount++;
        }

        return uniqueCount;
    }
}