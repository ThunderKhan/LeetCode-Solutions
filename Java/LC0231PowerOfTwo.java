public class LC0231PowerOfTwo{
    public static void main(String[] args){
        int n = 5;
        System.out.println(isPowerOfTwo(n));
    }

    public static boolean isPowerOfTwo(int n){
        if(n > 0 && (n & (n - 1)) == 0){
            return true;
        } else {
            return false;
        }
    }
}