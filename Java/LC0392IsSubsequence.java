public class LC0392IsSubsequence{
    public static void main(String[] args) {
        String s = "abc";
        String t = "ahbgdc";
        System.out.println(isSubsequence(s, t));
    }

    public static boolean isSubsequence(String s, String t){
        int sIdx = 0;
        int tIdx = 0;

        while((sIdx < s.length()) && (tIdx < t.length())){
            if(s.charAt(sIdx) == t.charAt(tIdx)){
                sIdx += 1;
            }
            tIdx += 1;
        }
        return sIdx == s.length();
    }   
}