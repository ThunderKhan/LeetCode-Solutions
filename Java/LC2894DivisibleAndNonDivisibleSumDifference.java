public class LC2894DivisibleAndNonDivisibleSumDifference{
    public static void main(String[] args){
        int n = 10;
        int m = 3;
        System.out.println(differenceOfSums(n, m));
    }

    public static int differenceOfSums(int n, int m){
        int total_sum = (n * (n + 1)) / 2;
        int k = n / m;
        int difference_sum = m * (k * (k + 1)) / 2;
        return total_sum - 2 * difference_sum;
    }
}