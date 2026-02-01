public class LC0326PowerOfThree{
    public static void main(String[] args){
        int n = 27;
        System.out.println(isPowerOfThree(n));
    }

    public static boolean isPowerOfThree(int n){
        if(n <= 0){
            return false;
        }

        while(n % 3 == 0){
            n /= 3;
        }

        return n == 1;
    }
}