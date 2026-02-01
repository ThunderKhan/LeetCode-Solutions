public class LC2769FindTheMaximumAchievableNumber{
    public static void main(String[] args){
        int num = 4;
        int t = 1;
        System.out.println(maximumAchievableX(num, t));
    }

    public static int maximumAchievableX(int num, int t){
        return num + 2 * t;
    }
}