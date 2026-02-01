import java.util.Arrays;

public class LC0259ThreeSumSmaller{
    public static void main(String[] args) {
        int[] nums1 = {-2, 0, 1, 3};
        int target1 = 2;
        System.out.println(threeSumSamller(nums1, target1));

        int[] nums2 = {-5, -4, -3, -2};
        int target2 = -3;
        System.out.println(threeSumSamller(nums2, target2));
    }

    public static int threeSumSamller(int[] nums, int target){
        int n = nums.length;
        int tripletCount = 0;
        Arrays.sort(nums);

        for(int i = 0; i < n - 2; i++){
            int left = i + 1;
            int right = n - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum < target){
                    tripletCount += (right - left);
                    left += 1;
                } else{
                    right -= 1;
                }
            }
        }

        return tripletCount;
    }
}