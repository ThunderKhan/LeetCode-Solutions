public class LC0125ValidPalindrome{
    public static void main(String[] args){
        String s = "A man, a plan, a canal: Panama";
        System.out.println(isPalindrome(s));
    }

    public static boolean isPalindrome(String s){
        String clean = s.replaceAll("[^a-zA-Z0-9]+", "").toLowerCase();

        int left = 0;
        int right = clean.length() - 1;

        while(left < right){
            if(clean.charAt(left) != clean.charAt(right)){
                return false;
            }
            
            left++;
            right--;
        }

        return true;
    }
}