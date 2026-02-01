public class LC0136SingleNumber{
    public static void main(String[] args){
        int[] arr = {1, 2, 3, 2, 1};
        System.out.println(singleNumber(arr));
    }

    public static int singleNumber(int[] nums) {
        int unique = 0;
        for(int num : nums) {
            unique ^=  num;
        }
        return unique;
    }
}