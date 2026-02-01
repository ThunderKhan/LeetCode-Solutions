public class LC1411NumberOfWaysToPaintNx3Grid{
    public static void main(String[] args){
        int n = 5000;
        System.out.println(numOfWays(n));
    }

    public static int numOfWays(int n){
        final int MOD = 1_000_000_007;

        long waysSame = 6;
        long waysDiff = 6;

        for(int i = 1; i < n; i++){
            long nextWaysSame = (3 * waysSame + 2 * waysDiff) % MOD;
            long nextWaysDiff = (2 * waysSame + 2 * waysDiff) % MOD;

            waysSame = nextWaysSame;
            waysDiff = nextWaysDiff;
        }

        return (int)((waysSame + waysDiff) % MOD);
    }
}