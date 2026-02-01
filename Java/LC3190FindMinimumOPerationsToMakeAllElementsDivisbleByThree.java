public class LC3190FindMinimumOPerationsToMakeAllElementsDivisbleByThree{
    public static void main(String[] args){
        int[] nums = {1, 2, 3, 4};
        System.out.println(minimumOperations(nums));
    }

    public static int minimumOperations(int[] nums){
        int counter = 0;

        for(int num : nums){
            if(num % 3 != 0){
                int k = num % 3;
                if(3 - k > k){
                    counter += k;
                } else{
                    counter += (3 - k);
                }
            }
        }

        return counter;
    }
}