public class LC0287FindTheDuplicateNumber{
    public static void main(String[] args){
        int[] nums = {1, 3, 4, 2, 2};
        int result = findDuplicate(nums);

        System.out.print("The Duplicate number is: ");
        System.out.println(result);
    }

    public static int findDuplicate(int[] nums){
        int slow = nums[0];
        int fast = nums[0];

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast){
                break;
            }
        }

        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
}