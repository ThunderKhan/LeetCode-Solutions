public class LC3110ScoreOfAString{
    public static void main(String[] args){
        String s = "hello";
        System.out.println(scoreOfString(s));
    }

    public static int scoreOfString(String s){
        int n = s.length();
        int score = 0;

        for(int i = 0; i < n - 1; i++){
            int curr = s.charAt(i);
            int next = s.charAt(i + 1);
            score += Math.abs(curr - next);
        }

        return score;
    }
}