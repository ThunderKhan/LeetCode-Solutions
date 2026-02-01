public class LC2413SamllestEvenMultiple{
    public static void main(String[] args){
        int n = 5;
        System.out.println(smallestEvenMultiple(n));
        
        int n = 6;
        System.out.println(smallestEvenMultiple(n));
    }

    public static int smallestEvenMultiple(int n){
        return (n % 2 == 0) ? n : 2 * n;
    }
}